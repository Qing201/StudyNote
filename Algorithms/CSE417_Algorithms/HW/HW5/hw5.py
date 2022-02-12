# CSE 417: Homework 5
# Name: Qingchuan Hou
# Student ID: 2127437
# UW NetID: qhou

import numpy as np
from time import time
import operator

# Version 1 using naive algorithm
def closest_v1(points_list):
    points_list = np.array(points_list)
    n = len(points_list)
    if n <= 1:
        if n == 1:
            return np.inf, points_list[0][0], points_list[0][1], points_list[0][0], points_list[0][1]
        else:
            return np.NaN

    else:
        min_dist = np.inf

        # comple the distance between two points for every point
        for i in range(n-1):
            for j in range(i+1,n):
                dist = np.linalg.norm(points_list[i] - points_list[j])
                if dist <= min_dist:
                    min_dist = dist
                    index1 = i
                    index2 = j
    
        return min_dist, points_list[index1][0], points_list[index1][1], points_list[index2][0], points_list[index2][1]


# Version 2
def closest_v2(points_list):
    points_list = np.array(points_list)
    n = len(points_list)
    if n <= 1:
        return np.inf, points_list[0][0], points_list[0][1], points_list[0][0], points_list[0][1]
    
    else:
        sort_points = sorted(points_list, key = operator.itemgetter(0,1))#points_list[np.argsort(points_list[:, 0])]

        m = n//2
        points1 = sort_points[0:m]
        points2 = sort_points[m:n]
        min_dist_1, x1_1, y1_1, x2_1, y2_1 = closest_v2(points1)
        min_dist_2, x1_2, y1_2, x2_2, y2_2 = closest_v2(points2)

        if min_dist_1 < min_dist_2:
            min_dist, x1, y1, x2, y2 = min_dist_1, x1_1, y1_1, x2_1, y2_1
        else:
            min_dist, x1, y1, x2, y2 = min_dist_2, x1_2, y1_2, x2_2, y2_2

        # find points in midlle area
        mid_points = np.array([p for p in sort_points if abs(p[0]-sort_points[m][0]) <= min_dist])

        mid_points_sort = np.array(sorted(mid_points, key = operator.itemgetter(1,0)))

        # Chech the distance between two points in middle area
        for i in range(len(mid_points_sort)-1):
            for j in range(i+1, len(mid_points_sort)):
                if min_dist >= mid_points_sort[j][1] - mid_points_sort[i][1]:
                    dist = np.linalg.norm(mid_points_sort[i] - mid_points_sort[j])
                    if dist < min_dist:
                        min_dist = dist
                        x1, y1 = mid_points_sort[i][0], mid_points_sort[i][1]
                        x2, y2 = mid_points_sort[j][0], mid_points_sort[j][1]
                else:
                    break
        
    return min_dist, x1, y1, x2, y2


# Version 3
def closest_v3(points_list):
    points_list = np.array(points_list)
    n = len(points_list)
    if n <= 1:
        return np.inf, points_list[0][0], points_list[0][1], points_list[0][0], points_list[0][1]
    
    else:
        sort_points = sorted(points_list, key = operator.itemgetter(0,1))
        min_dist, x1, y1, x2, y2 = v3_loop(sort_points)
    
    return min_dist, x1, y1, x2, y2


def v3_loop(points_list):
    n = len(points_list)
    if n <= 1:
        return np.inf, points_list[0][0], points_list[0][1], points_list[0][0], points_list[0][1]
    
    else:

        m = n//2
        points1 = points_list[0:m]
        points2 = points_list[m:n]
        min_dist_1, x1_1, y1_1, x2_1, y2_1 = v3_loop(points1)
        min_dist_2, x1_2, y1_2, x2_2, y2_2 = v3_loop(points2)

        if min_dist_1 < min_dist_2:
            min_dist, x1, y1, x2, y2 = min_dist_1, x1_1, y1_1, x2_1, y2_1
        else:
            min_dist, x1, y1, x2, y2 = min_dist_2, x1_2, y1_2, x2_2, y2_2

        # find points in midlle area
        mid_points = np.array([p for p in points_list if abs(p[0]-points_list[m][0]) <= min_dist])

        mid_points_sort = np.array(sorted(mid_points, key = operator.itemgetter(1,0)))

        # Chech the distance between two points in middle area
        for i in range(len(mid_points_sort)-1):
            for j in range(i+1, len(mid_points_sort)):
                if min_dist >= mid_points_sort[j][1] - mid_points_sort[i][1]:
                    dist = np.linalg.norm(mid_points_sort[i] - mid_points_sort[j])
                    if dist < min_dist:
                        min_dist = dist
                        x1, y1 = mid_points_sort[i][0], mid_points_sort[i][1]
                        x2, y2 = mid_points_sort[j][0], mid_points_sort[j][1]
                else:
                    break
        
    return min_dist, x1, y1, x2, y2


def points_list(text):

    points = list()

    while text:
        u = float(text.pop(0))
        v = float(text.pop(0))
        points += [[u,v]]

    return np.array(points)


def print_function(n, x1, y1, x2, y2, min_dist, run_time):
    if x1 > x2:
        x1, x2 = x2, x1
        y1, y2 = y2, y1

    if x1 == x2 and y1 > y2:
        x1, x2 = x2, x1
        y1, y2 = y2, y1

    print('%d,  %.3f, %.3f, %.3f, %.3f, %.3f, %.3f' % (n, x1, y1, x2, y2, min_dist, run_time))


def cvs():
    # Try to open each file by sequence
    import pandas as pd
    df = pd.DataFrame(columns=['n','sq_run_time_v1', 'sq_run_time_v2', 'l_run_time_v1', 'l_run_time_v2'])
    
    for n in range(1, 10):

        # unit square
        sq_list = []
        for i in np.linspace(0,1,n):
            for j in np.linspace(0,1,n):
                sq_list += [[i,j]]
            

        start_time_v1 = time()
        closest_v1(sq_list)
        end_time_v1 = time()

        sq_run_time_v1 = (end_time_v1 - start_time_v1) * 1000

        start_time_v2 = time()
        min_dist_v2, x1_v2, y1_v2, x2_v2, y2_v2 = closest_v2(sq_list)
        end_time_v2 = time()

        sq_run_time_v2 = (end_time_v2 - start_time_v2) * 1000

        # line
        l_list = []
        for i in np.linspace(0,1,n**2):
            l_list += [[0,i]]
        l_list = np.array(l_list)
        start_time_v1 = time()
        min_dist_v1, x1_v1, y1_v1, x2_v1, y2_v1 = closest_v1(l_list)
        end_time_v1 = time()

        l_run_time_v1 = (end_time_v1 - start_time_v1) * 1000

        start_time_v2 = time()
        min_dist_v2, x1_v2, y1_v2, x2_v2, y2_v2 = closest_v2(l_list)
        end_time_v2 = time()

        l_run_time_v2 = (end_time_v2 - start_time_v2) * 1000
    
        df = df.append({'n' : n**2 , 'sq_run_time_v1' : sq_run_time_v1,  'sq_run_time_v2' : sq_run_time_v2, 'l_run_time_v1': l_run_time_v1, 'l_run_time_v2': l_run_time_v2}, ignore_index=1)

    df.to_csv('run_time.csv')   

    return df     


def plot(df):
    import matplotlib.pyplot as plt
    
    x = df['n']
    y = df['l_run_time_v1']

    fig,ax = plt.subplots()
    ax.scatter(x, y, label='Naive Algorithm')

    z = np.polyfit(x, y, 2)
    p = np.poly1d(z)
    ax.plot(x,p(x),"r--", alpha=0.3)

    ax.legend()

    x1 = df['n']
    y1 = df['l_run_time_v2']


    ax.scatter(x1, y1, label='Divide and Comquer Algorithm')

    z1 = np.polyfit(x1, y1, 2)
    p1 = np.poly1d(z1)
    ax.plot(x1,p1(x1),"r--", alpha=0.3)
    ax.set_title('Algorithm Run Time in Unit Line')
    ax.set_ylabel('Run Time')
    ax.set_xlabel('Points Number')
    ax.legend()

    plt.show()



def main(v3=False):
    # Read points from list
    text = list()

    while True:
        try:
            text += input().split()
        except EOFError:
            break;  

    points = points_list(text)

    n = len(points)

    # Closest pair
    start_time_v1 = time()
    min_dist_v1, x1_v1, y1_v1, x2_v1, y2_v1 = closest_v1(points)
    end_time_v1 = time()

    run_time_v1 = (end_time_v1 - start_time_v1) * 1000

    start_time_v2 = time()
    min_dist_v2, x1_v2, y1_v2, x2_v2, y2_v2 = closest_v2(points)
    end_time_v2 = time()

    run_time_v2 = (end_time_v2 - start_time_v2) * 1000

    print('Version 1, ', end='')
    print_function(n, x1_v1, y1_v1, x2_v1, y2_v1, min_dist_v1, run_time_v1)
    print('Version 2, ', end='')
    print_function(n, x1_v2, y1_v2, x2_v2, y2_v2, min_dist_v2, run_time_v2)

    if v3 == True:
        start_time_v3 = time()
        min_dist_v3, x1_v3, y1_v3, x2_v3, y2_v3 = closest_v3(points)
        end_time_v3 = time()

        run_time_v3 = (end_time_v3 - start_time_v3) * 1000

        print('Version 3, ', end='')
        print_function(n, x1_v3, y1_v3, x2_v3, y2_v3, min_dist_v3, run_time_v3)


if __name__ == '__main__':

    # Using v3 = 1 to use version 3, and =0 to ignore
    main(v3 = 1)
    # cvs()