#### CSE 417: Homework 7
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 5:
a) A counter example:
If given a $x$ = {4, 1, 2, 3}, where the $x_1$ > $x_4$ > $x_3$ > $x_2$, the best socially distant subset is $D$ = {1, 4}. Neither the sum by odd number $D$ = {1, 3} or the sum by even number $D$ = {2, 4} can give the best socially distant subset $D$

</br>

b) A counter example:
If given a $x$ = {4, 6, 5}, when sort the $x$ and pick the bigest one $x_2$=6. The other two $x$ is adjacent to $x_2$, so neither of the rest two can be picked. In this situation, the $D$ = {2}.  However, $x_1$ + $x_3$ > $x_2$, the best socially distant subset is $D$ = {1, 3}, not $D$ = {2}.

</br>

c) 
In this problem, we can use the dynamic algorithm to find the max sum of the first n number of $x$, MAX[n]. Every time a new $x$ come in, we can add $x_n$ to update MAX[n]. In this problem, we can not put two nearby numbers together, so we can not get the MAX[n] by adding $x_n$ to MAX[n-1], $x_n$ can only be added by MAX[n-2]. Therefore, The MAX[n] can be chose by the bigger one of MAX[$n$-1] and MAX[$n$-2] + $x_i$

**Pseudocode:**
    
    Creat a list M to store evey MAX[n]          // use to max() function and traceback
    MAX[n]:
        if n == 0:
            MAX[n] = 0
        if n == 1:      //Because there is a MAX[n-2] in the algorithm, so we need initalize MAX[1]
            MAX[n] = x_1
        else:
            MAX[n] = max( MAX[n-1], MAX[n-2] + x_n}
        store MAX[n] -> M
        return MAX[n]
    output MAX[n]

</br>

After find the MAX[n], we can use traceback to find which element has been added to the max sum.

**Pseudocode:**
    
    Find-D[MAX[n]]:
        if MAX[n] == 0:
            output None
        elif MAX[n] == x_1:
            output 1
        elif MAX[n] == MAX[n-1]:
            MAX[n-1]
        else:
            output n
            MAX[n-2]

The every output is the best socially distant subset $D$

**Run time:**
For the dynamic algorithm, every n will run once to find MAX[n], so the run time is $O(n)$. For the traceback algorithm, every n will also run once by compare MAX[n] to find if $x_n$ has been added or not. The run time is also $O(n)$. Therefore, the total run time is:
$$O(n) + O(n) = O(n)$$

</br>

</br>

d)
n | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 
- | - | - | - | - | - | - | - | - | - 
$x_n$ | - | 12 | 14 | 11 | 1 | 2 | 9 | 13 | 8 |
MAX [n] | 0 | 12 | 14 | 23 | 23 | 25 | 32  | 36 | 40

**Campare with 3 algorithms:**
- **Algorithm a:**
 Sum of odd n = 12 + 11 + 2 + 13 = 38
Sum of even n = 14 + 1 + 9 + 8 = 32
Max-Sum = max (38, 32) = 38, solution is D = {1, 2, 3, 4}

- **Algorithm b:**
Chosing sequence: $x_2$ -> $x_7$ -> $x_5$, the rest elements is adjecent to one of selected $x$. 
Max-Sum = 14 + 13 + 2 = 29
Solution: D = {2, 7, 5}


- **Dynamic Algorithm:**
  Max-Sum = MAX[8] = 40
  Solution: D = {1, 3, 6, 8} &emsp; &emsp; &emsp; ** Using traceback to find the solution, showing on the table*

