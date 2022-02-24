import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import time 
import alpaca_trade_api as alpaca 
from alpaca_trade_api.rest import REST, TimeFrame, TimeFrameUnit
from datetime import date, timedelta
from statsmodels.tsa.seasonal import STL
from scipy.sparse.construct import random
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split

ENDPOINT="https://paper-api.alpaca.markets"
API_KEY_ID="PKWZKHKD4A9KWO4KHLH1" # Put in yours here - Needed for paper trading
SECRET_KEY="LDg93NwvTIfiiPFt3R1B6mJnVQuPaD5EuXwPWSv6" # Put in yours here - Needed for paper trading


class TradingStrategy:
    def __init__(self,STOCK):
        self.api = alpaca.REST(API_KEY_ID, SECRET_KEY, ENDPOINT)
        self.STOCK = STOCK
        self.SELL_LIMIT_FACTOR = 1.01 # 1 percent margin
        self.data = self.get_nearst_past_data()
        self.last_operated_date = None
        self.fited_modle = None
        self.modle_name = str()
        self.predict_now = 0
    

    def get_past_data(self, start=date.today()-timedelta(days=90), end=date.today()-timedelta(days=1), n=None):
        return self.api.get_bars(self.STOCK, TimeFrame.Day, start=start, end=end, adjustment='raw', limit=n).df


    def get_nearst_past_data(self, day=90, n=1000, time_frame='15Min'):#TimeFrame(16, TimeFrameUnit.Minute)):
        start_date = date.today() - timedelta(days=day)
        end_date = date.today()-timedelta(minutes=16)-timedelta(hours=1)-timedelta(days=0)
        
        barset = self.api.get_barset(self.STOCK, timeframe=time_frame, limit=n).df
        self.data = barset[self.STOCK]
        self.LAST_DATE = self.data.index.values[n-1]

        #self.data = self.api.get_bars(self.STOCK, timeframe=time_frame, start=start_date, end=end_date, adjustment='raw', limit=n).df


    def data_prep(self, data_name='close', label_strategy='local', label_plot=False, update=False):
        data1 = self.SMA_EMA(data_name)
        data2 = self.STL(data_name)
        data = pd.concat([data1, data2], axis=1)
        data['label_'+label_strategy] = self.label(label_strategy=label_strategy, plot=label_plot)
        data = data.dropna()
        if update == True:
            self.data = data
        return data



    def SMA_EMA(self, data_name='close', update=False):
        data = self.data[data_name].to_frame()
        for n in np.arange(5,50,10):
            data['SMA-'+str(n)] = self.data[data_name].rolling(window=n).mean()
            data['EMA-'+str(n)] = self.data[data_name].ewm(span=n,min_periods=0,adjust=False,ignore_na=False).mean()
        if update == True:
            self.data = data
        return data
        

    def STL(self, data_name='close', update=False, p=12):
        res = STL(self.data[data_name],period=p).fit()
        data = pd.DataFrame()
        data['stl_seasonal'] = res.seasonal
        data['stl_resid'] = res.resid
        data['stl_trend'] = res.trend
        if update == True:
            self.data = pd.concat([self.data, data], axis=1)
        return data
    
    
    def maket_operation(self, n=365, time_frame='15Min', testsize=0.2):

        self.get_nearst_past_data(n=n, time_frame=time_frame)
        self.train(testsize=testsize)
        
        if self.last_operated_date != self.LAST_DATE:
            # buy
            if self.predict_now == 1:
                self.market_buy_strategy()
                self.BOUGHT = 1
                print('Buy:', self.STOCK)
            
            # sell
            elif self.predict_now == -1 and self.BOUGHT == 1:
                self.market_sell_strategy()
                self.BOUGHT = 0
                print('Sell', self.STOCK)
                
            self.last_operated_date = self.LAST_DATE



    def get_current_price(self):
        return float(self.api.get_latest_trade(self.STOCK).price)
    
    def get_quantity_buy(self):
        if int(float(self.api.get_account().cash)) > 20000:
            return int(float(10000) / self.get_current_price())

        elif int(float(self.api.get_account().cash)) > 0:
            return int((float(self.api.get_account().cash)/2) \
                       /self.get_current_price())
        else:
            return 0
        
    def exists_buy_order(self):
        # Identifies if a buy order exists for a stock
        orders = self.api.list_orders()
        for order in orders:
            if order.side=="buy" and order.symbol==self.STOCK:
                return True
        
        return False
    
    def have_bought_stock(self):
        positions=self.api.list_positions()
        for position in positions:
            if position.symbol==self.STOCK and int(position.qty)==self.NEW_QUANTITY + self.EXISTING_QUANTITY:
                return True
        return False
        
        
    def get_buy_price(self):
        # Identify the buying price for a stock
        positions=self.api.list_positions()
        for position in positions:
            if position.symbol==self.STOCK:
                return float(position.cost_basis)/int(position.qty)
    
    
    def buy_market_order(self):
        # Buy the stock at market price (This is for paper-trading)
        if self.NEW_QUANTITY > 0:
            self.api.submit_order(self.STOCK, \
                        qty=self.NEW_QUANTITY,\
                        side="buy",\
                        type="market", \
                        time_in_force="day",
                        order_class=None)
        
    def buy_limit_order(self,base_price):
        pass
        
    def sell_market_order(self):
        # (This is for paper-trading)
        if self.NEW_QUANTITY > 0:
            self.api.submit_order(self.STOCK, \
                        qty=self.NEW_QUANTITY + self.EXISTING_QUANTITY,\
                        side="sell",\
                        type="market", \
                        time_in_force="day",
                        order_class=None)
        # Your code if you want to sell at limit
        # Check Alpaca docs on selling at limit


    def identify_strategy_for_selling(self):
        # If you have multiple strategies
        # Pick between them here - Or use ML to help identify 
        # your strategy
        pass
        
        
    def market_buy_strategy(self):
        # Providing a simple trading strategy here:
        # Buy at market price if conditions are favorable for buying
        # Sell at a limit price that is determined based on buying price
        # This strategy doesn't use any ML here - You may want to use
        # appropriate libraries to train models + use the trained strategy 
        # here
        
        # Get existing quantity
        positions = self.api.list_positions()
        self.EXISTING_QUANTITY = 0
        for position in positions:
            if position.symbol == self.STOCK:
                self.EXISTING_QUANTITY += int(position.qty)
                
        # MARKET BUY order
        self.NEW_QUANTITY=self.get_quantity_buy()
        
        if self.NEW_QUANTITY == 0:
            return "ZERO EQUITY"
        
        self.buy_market_order()
            
    
    def market_sell_strategy(self):
        # BRACKET SELL order
        # Initiate sell order if stock has been bought
        # If not, wait for it to be bought
        while not self.have_bought_stock():
            #print(self.api.positions)
            #print(self.NEW_QUANTITY + self.EXISTING_QUANTITY)
            time.sleep(1)
        
        if self.have_bought_stock():
            #buy_price=self.get_buy_price()
            #self.SELL_LIMIT_PRICE=int(float(buy_price))*self.SELL_LIMIT_FACTOR
            
            # Initiate Sell order
            self.sell_limit_order()


    # chose the label strategy and lableling
    def label(self, label_strategy='local', data_name='close', update=False, plot=False):
        if label_strategy == 'local':
            labels =  self.__label_local(update)

        if plot == True:

            df_label = pd.DataFrame(self.data[data_name])
            df_label['label'] = labels
            df_label_buy = df_label.loc[df_label['label'] == 1]
            df_label_sell = df_label.loc[df_label['label'] == -1]

            fig,ax = plt.subplots()
            fig.set_size_inches(18.5, 10.5, forward=True)

            ax.plot(df_label.index.values, df_label[data_name])
            ax.scatter(df_label_buy.index.values, df_label_buy[data_name], marker='^', c='r', linewidths=3, label='Buy')
            ax.scatter(df_label_sell.index.values, df_label_sell[data_name], marker='v', c='g', linewidths=3, label='Sell')
            ax.set_xlabel('Data')
            ax.set_ylabel('Value')
            ax.set_title('Buy and Sell Self-labelling')
            ax.legend(fontsize='xx-large')

            plt.show()

        return labels 
 

    # local min and max label strategy
    def __label_local(self, update=False, data_name='close'):

        labels = np.zeros(len(self.data))
        closing = self.data[data_name]
        closing.shape
        
        for i in range(len(closing)):
            if i <= 1 or i >= len(closing)-2:
                labels[i] = 0
            
            # buy points
            elif closing[i+2] > closing[i] and closing[i] < closing[i-2]:
                labels[i] = 1

            # sell poinsts
            elif closing[i-2] < closing[i] and closing[i+2] < closing[i]:
                labels[i] = -1
            else:
                labels[i] = 0
        if update == True:
            self.data['label_local'] = labels
        return labels


    def train(self, label_strategy='local', train_modle='LR', label_plot=False, data_name='close', predict_plot=False, money_pred=False, testsize=5/12):
        # data pre-procesing
        data = self.data_prep(label_strategy=label_strategy, label_plot=label_plot)
        label_name = 'label_'+label_strategy
        X = data.drop([label_name],axis=1)
        y = data[label_name]
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=testsize,shuffle=False)

        # training step
        if train_modle == 'LR':
            modle = LogisticRegression(random_state=0, max_iter=10000).fit(X_train,y_train)
        self.fited_modle = modle
        self.modle_name = train_modle

        test_prediction = modle.predict(X_test)
        self.predict_now = test_prediction[len(test_prediction)-1]
        
        # print('Model prediction accuracy with true label:', modle.score(X_test,y_test))
        
        # predict plot
        if predict_plot == True:
            df_label = pd.DataFrame(X_test[data_name])
            df_label['label'] = test_prediction
            df_label_buy = df_label.loc[df_label['label'] == 1]
            df_label_sell = df_label.loc[df_label['label'] == -1]

            fig,ax = plt.subplots()
            fig.set_size_inches(18.5, 10.5, forward=True)

            ax.plot(df_label.index.values, df_label[data_name])
            ax.scatter(df_label_buy.index.values, df_label_buy[data_name], marker='^', c='r', linewidths=3, label='Buy')
            ax.scatter(df_label_sell.index.values, df_label_sell[data_name], marker='v', c='g', linewidths=3, label='Sell')
            ax.set_xlabel('Data')
            ax.set_ylabel('Value')
            ax.set_title('Buy and Sell Predict Label with '+self.STOCK)
            ax.legend(fontsize='xx-large')

            plt.show()

        # predict money
        if money_pred == True:
            bought_money = 0
            sell_moneny = 0
            max_money = 0
            quantity = 0
            earned_money = 0
            for i in range(len(X_test)):
                if test_prediction[i] == 1:
                    bought_money += 100
                    quantity += 100/X_test[data_name][i]
                if test_prediction[i] == -1 and bought_money != 0:
                    max_money = max(max_money, bought_money)
                    sell_moneny = quantity*X_test[data_name][i]
                    earned_money += sell_moneny - bought_money
                    bought_money = 0
                    quantity = 0

            max_money = max(max_money, bought_money)
            sell_moneny = quantity*X_test[data_name][len(X_test)-1]
            earned_money += sell_moneny - bought_money

            print('Money used:', max_money)
            print('Money earned:', earned_money)
            print(f'Return:{100*earned_money/max_money}%')


import warnings
warnings.filterwarnings("ignore", category=DeprecationWarning) 




'''
timeframe: One of minute, 1Min, 5Min, 15Min, day or 1D. minute
               is an alias of 1Min. Similarly, day is of 1D.
'''
def maket(stock_list, n=365, sleep_time=3600, data_freq='15Min', test_size=0.2):  
    S=[]
    for stock in stock_list:
        S.append(TradingStrategy(stock))
    while True:
        for s in S:
            s.maket_operation(n=n, time_frame=data_freq, testsize=test_size)
        time.sleep(sleep_time)

def main():
    stock_list = ['AAPL', 'BILI', 'TSLA', 'GOOG', 'NTES']
    maket(stock_list, sleep_time=5)

if __name__ == '__main__':
    main()
