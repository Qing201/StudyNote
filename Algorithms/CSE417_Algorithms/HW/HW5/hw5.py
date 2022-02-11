from operator import index
import numpy as np
from time import time


def closet_v1(points_list):
    n = len(points_list)
    if n <= 1:
        return None
    
    else:
        start_time = time()
        dist = np.linalg.norm(points_list[0] - points_list[1])
        for i in range(n-1):
            for j in range(i+1,n):
                dist = np.linalg.norm(points_list[i] - points_list[j])
                if dist < min_dist:
                    min_dist = dist
                    index1 = i
                    index2 = j
        end_time = time()
        run_time = (end_time - start_time) * 1000

        if points_list[i][0] >= points_list[j][0]:
            if points_list[i][0] == points_list[j][0]:
                if points_list[i][0] > points_list[j][0]:
                    temp = j
                    i = j

                

        print('Version 1', n, min_dist, 



def points_list(text):

    points = list()

    while text:
        u = float(text.pop(0))
        v = float(text.pop(0))
        points += [[u,v]]

    return np.array(points)


def main():

    text = list()

    while True:
        try:
            text += input().split()
        except EOFError:
            break;  

    points = points_list(text)





def test():
    text = list()
    text += input()#.split()
    print(text)
    pass


main()
#test()