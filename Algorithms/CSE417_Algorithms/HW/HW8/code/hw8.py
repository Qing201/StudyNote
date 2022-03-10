import numpy as np
from time import time


class RNA():

    def __init__(self, rnalist):
        self.rna_list = rnalist
        self.opt_list = None
        self.traceback_list = None


    # Compute the OPT list using Nussino's algorithm
    def opt(self):

        n = len(self.rna_list)
        self.opt_list = np.zeros((n,  n))

        for j in range(5,n):
            for i in range(j-5, -1, -1):        # i should < j-4, the biggest i is j-5
                opt_temp = 0
                for t in range(i, j-4):
                    if self.pair_check(self.rna_list[t], self.rna_list[j]):
                        if t==0:                    # t-1 = -1, so set opt_list[i, t-1] = 0
                            opt_temp = max(0 + self.opt_list[t+1, j-1] + 1, opt_temp)
                        else:
                            opt_temp = max(self.opt_list[i, t-1] + self.opt_list[t+1, j-1] + 1, opt_temp)
                self.opt_list[i, j] = max(self.opt_list[i, j-1], opt_temp)
        return self.opt_list


    def traceback(self):
        # initall the traceback list
        n = len(self.opt_list[0])
        self.traceback_list = np.zeros(n)

        # call the traceback loop to find solution
        self.traceback_list = self.traceback_loop(0, n-1)
        return self.traceback_list


    def traceback_loop(self, i, j):
        opt_num = self.opt_list[i,j]
        if opt_num == 0:
            pass
        elif self.opt_list[i, j] == self.opt_list[i, j-1]:
            self.traceback_list = self.traceback_loop(i, j-1)
        else:
            self.traceback_list[j] = 1

            for t in range(i, j-4):
                if self.pair_check(self.rna_list[t], self.rna_list[j]):
                    # when t=0, t-1 = -1, it out of range, so assume opt_list[i, t-1] = 0
                    if t == 0 and self.opt_list[1, j-1] + 1 ==  self.opt_list[i, j]:
                        self.traceback_list[0] = -1
                        self.traceback_list = self.traceback_loop(1, j-1)
                        break

                    elif self.opt_list[i, t-1] + self.opt_list[t+1, j-1] + 1 ==  self.opt_list[i, j]:
                        self.traceback_list[t] = -1
                        self.traceback_list = self.traceback_loop(t+1, j-1)
                        self.traceback_list = self.traceback_loop(i, t-1)
                        break

        return self.traceback_list


    def pair_check(self, a, b):
        if (a == 'A' and b == 'U') or (a == 'U' and b == 'A') or (a == 'C' and b == 'G') or (a == 'G' and b == 'C'):
            return True

        # for timing random sequence
        elif (a == 0 and b == 1) or (a == 1 and b == 0) or (a == 2 and b == 3) or (a == 3 and b == 2):
            return True

        else:
            return False


# timming test
def timing(plot=False):
    num_list = []
    time_list = []
    for n in range(5, 100, 5):
        for i in range(3):
            rna_list = np.random.randint(4, size=n)
            R = RNA(rna_list)

            start_time = time()
            opt_list = R.opt()
            R.traceback()
            end_time = time()

            runtime = 1000 * (end_time - start_time)
            
            num_list.append(n)
            time_list.append(runtime)
    
    if plot == True:
        import matplotlib.pyplot as plt

        x = np.array(num_list)
        y = np.array(time_list)

        fig,ax = plt.subplots()
        ax.scatter(x, y, label='Runtime')

        z = np.polyfit(x, y, 3)
        p = np.poly1d(z)
        ax.plot(x,p(x),"r--", alpha=0.3)

        ax.set_title('Nussinov\'s Algorithm Run Time')
        ax.set_ylabel('Run Time (ms)')
        ax.set_xlabel('Elements Number n')
        ax.legend()

        plt.show()


    return num_list, time_list



def main(timing_test=False, timing_plot=False):
    # Read points from list
    text = list()

    while True:
        try:
            line = input()
        except EOFError:
            break

        line = line.replace(" ", "")

        if line.startswith('#'):
            pass

        rna = line.split()              # will ignal the blank space
        if rna:
            text.append(line) 

    for rna in text:

        rna_list = list(rna)
                
        R = RNA(rna_list)

        start_time = time()
        opt_list = R.opt()
        result_list = R.traceback()
        end_time = time()

        runtime = 1000 * (end_time - start_time)

        # print result
        print(rna)

        if len(result_list) != len(rna_list):
            print('not same')

        for a in result_list:
            if a == 0:
                print('.', end='')
            if a == -1:
                print('(', end='')
            if a == 1:
                print(')', end='')
        print()

        if len(opt_list) <= 15:
            for raw in opt_list:
                for num in raw:
                    print('%d' % num, end=' ')
                print()

        n = len(list(rna))
        print('Summary: %d, %d, %.6f' % (opt_list[0, n-1], n, runtime))
        print()

    
    if timing_test == True and timing_plot == False:
        num_list, time_list = timing()
        return num_list, time_list

    elif timing_plot == True:
        num_list, time_list = timing(plot=1)
        return num_list, time_list



if __name__ == '__main__':

    main(timing_test=0, timing_plot=0)   

    # set timing_test=1 to turn on the timming test

    # num_list, time_list = main(timing_test=1, timing_plot=1)

    # set timing_plot=1 to show the runtime plot
