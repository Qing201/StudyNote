#### CSE 417: Homework 6
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 3:
These two sorted array $A$ and $B$ both have $n$ numbers *($n$ = 2$k$ +1)*. Because these two array are sorted, if there the middle number of $A \cup B$ is $a_i$ in array $A$, then there will have $b_{n-i} < a_i < b_{n-i+1}$ in array $B$. According to this, we can search the number in array $A$ which meets the requirement above.

First, choosing the middle number in A, which is $a_{k+1}$, compare with $b_k$ and $b_{k+1}$. If it does not meet the requirement and $a_k < b_{n-k}$, the $a_k$ is small, then picking another number $a_i$ in the middle of bigger half of A. If $a_k > b_{n-k+1}$, pick the number in the small half of A. Repeat these steps and pick the middle number in half array every time, until find the last one number.  

There also have another situation is that if the middle point is not in A, in this case we need check the last result number for the recursive algorithm, if the last one is $a_i$, from the previous step, we wil also have $a_{i+1} > b_{n-i}$ or $i=n$, and $a_{i-1} < b_{n-i+1}$ or $i=1$. Therefore, 
1. if $ a_i < b_{n-i}$ and $n != i$, will have $ a_i < b_{n-i} < a_{i+1} $, and $i+(n-i) = n$, so $b_{n-i}$ will be the middle numble.
2. if $ a_i > b_{n-i+1}$, will have $ a_{i-1} < b_{n-i+1} < a_i $ or $a_1>b_n$, and $(i-1)+(n-i+1) = n$, so $b_{n-i+1}$ will be the middle numble.

Otherwise, $a_i$ will be the middle number. This also include if n=i, $a_n < b_1$, $a_n$ will be the middle number.

</br>

**Pseudocode:**
(1) Middle Point Comparison($A_{(i \text{ to } j )}, B$):        &emsp; &emsp; &emsp; &emsp; // i =1, j = n for first operation
(2) &emsp; &emsp; if i == j: &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; // only one element in array A
(3) &emsp; &emsp; &emsp; &emsp; if ($i$ != $n$  and $ a_i < b_{n-i}$), &emsp; return $b_{n-i}$
(4) &emsp; &emsp; &emsp; &emsp; elif ($ a_i > b_{n-i+1}$), &emsp; return $b_{n-i+1}$
(5) &emsp; &emsp; &emsp; &emsp; else &emsp; return $a_i$

(6) &emsp; &emsp; $m = (i+j) / 2$

(7) &emsp; &emsp; if $a_m > b_{n-m+1}$ \
(8) &emsp; &emsp; &emsp; &emsp; $p$ = Middle Point Comparison( First half: $A_{(i \text{ to } m-1 )}, B$ ) \
(9) &emsp; &emsp; elif $a_m < b_{n-m}$ \
(10) &emsp;&emsp;&emsp; &emsp; $p$ = Middle Point Comparison( Second half: $A_{(m+1 \text{ to } j )}, B$ ) \
(11) &emsp;&emsp;return $p$

</br>

Operations to count: the value comparison between two points

Base case: lines (2) - (5)
Recursive calls: lines (8) and (10)
Counted operation: 
1. The comparison in one recursive level: lines (7) and (9)
2. The comparison in base case: lines (3) and (4)

Corresponding recurrence relation:
$$ 
\begin{align*}
    T(n) = 
    \begin{cases}
    2 & \text{for } n < 2 \\
    T(n/2) + c & \text{otherwise} 
    \end{cases}
\end{align*} 
$$
Where a=1, b=2, c=2, d=2, k=0
1. a stands for the number of problems need to consider after every time divide. I only need to consider half of the array after every time I divide, so there will only have one problem. That is why a=1.
2. b stands for the size after every time divide. In the algorithm, the divide will divide the full array into two half parts, which is n/2 so that is why b = 2.
3. c and k are both standing for the number of counted operations in one recursive level. Every recursive level has 1 or 2 comparisons, line (7) and (9). I picked the bigger number, so c = 2. Because these comparisons is constant, they are not decided $n$ in the recursive level, the exponent of $n$ term k = 0.
4. d is standing for the number of counted operations in the base case. There are 1 or 2 comparisons in base level, line (3), and (4) in Pseudocode. So d = 2 by picking the bigger number.

$a = b^k$, so the complexity of algorithm is,
$$T(n) = \Theta (n^klogn) = \Theta(logn)$$