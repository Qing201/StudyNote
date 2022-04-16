#!/usr/bin/env python
# coding: utf-8

# In[4]:


import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import time
import sys
import alpaca_trade_api as alpaca
from alpaca_trade_api.rest import REST, TimeFrame, TimeFrameUnit
from datetime import date, timedelta, datetime
from statsmodels.tsa.seasonal import STL
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split

ENDPOINT="https://paper-api.alpaca.markets"
API_KEY_ID="PKDM4OTV4Q3U8Z233JSZ" # Put in yours here - Needed for paper trading
SECRET_KEY="ERKYkegTMOMlnYlGSElN2zFYwm9L4kumBvINiLeC" # Put in yours here - Needed for paper trading


# In[5]:


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
        self.BOUGHT = 0
        self.df = self.DoulMA()

    def get_nearst_past_data(self, day=90, n=1000, time_frame='15Min'):#TimeFrame(16, TimeFrameUnit.Minute)):
        start_date = date.today() - timedelta(days=day)
        end_date = date.today()-timedelta(minutes=16)-timedelta(hours=1)-timedelta(days=0)

        barset = self.api.get_barset(self.STOCK, timeframe=time_frame, limit=n).df
        self.data = barset[self.STOCK]
        self.LAST_DATE = self.data.index.values[len(self.data)-1]
        return self.data
    
    def DoulMA(self,window1=15,window2=25):
        sma1 = pd.DataFrame()
        sma2 = pd.DataFrame()
        sma1['sma15'] = self.data['close'].rolling(window = window1).mean()
        sma2['sma25'] = self.data['close'].rolling(window = window2).mean()
        df = pd.DataFrame()
        df['AAPL'] = self.data['close']
        df['SMA'+str(window1)] = sma1['sma15']
        df['SMA'+str(window2)] = sma2['sma25']
        return df
    
    def dualMACrossover(self):
        data = self.df
        if data['SMA'+str(window1)][-1]/data['SMA'+str(window2)][-1] > 1.005 :
            self.predict_now = 1
        elif data['SMA'+str(window1)][-1]/data['SMA'+str(window2)][-1] < 0.995:
            self.predict_now = -1
        else:
            self.predict_now = 0   



    def maket_operation(self, n=365, time_frame='15Min', testsize=0.2):

        self.get_nearst_past_data(n=n, time_frame=time_frame)

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

            else:
                print('Hold:', self.STOCK)

            self.last_operated_date = self.LAST_DATE



    def get_current_price(self):
        return float(self.api.get_latest_trade(self.STOCK).price)

    def get_quantity_buy(self):
        if int(float(self.api.get_account().cash)) > 20000:
            return int(float(10000) / self.get_current_price())

        elif int(float(self.api.get_account().cash)) > 0:
            return int((float(self.api.get_account().cash)/2)                        /self.get_current_price())
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
            self.api.submit_order(self.STOCK,                         qty=self.NEW_QUANTITY,                        side="buy",                        type="market",                         time_in_force="day",
                        order_class=None)

    def buy_limit_order(self,base_price):
        pass

    def sell_market_order(self):
        # (This is for paper-trading)
        if self.NEW_QUANTITY > 0:
            self.api.submit_order(self.STOCK,                         qty=self.NEW_QUANTITY + self.EXISTING_QUANTITY,                        side="sell",                        type="market",                         time_in_force="day",
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


# In[ ]:


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
        print('\rChecking: ', datetime.now())
        for s in S:
            s.maket_operation(n=n, time_frame=data_freq, testsize=test_size)
        print('Sleeping...')
        time.sleep(sleep_time)



def plot(stock_list, n=365, sleep_time=3600, data_freq='15Min', test_size=0.2): 
    S=[]
    for stock in stock_list:
        S.append(TradingStrategy(stock))
    for s in S:
        s.get_nearst_past_data(n=n, time_frame=data_freq)
        s.train(testsize=test_size, predict_plot=1, money_pred=1)


if __name__ == '__main__':
    stock_list = ['AAPL', 'BILI', 'TSLA', 'GOOG', 'NTES']
    maket(stock_list, n=1000, data_freq='15Min', test_size=0.1, sleep_time=3600)
    # plot(stock_list, n=1000, data_freq='15Min', test_size=0.1)


# In[ ]:




