#### CSE 417: Homework 6
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 4:
The divide and conquer algorithm for this problem have two-part, the divide part and conquer part. 
1. First, we need to divide the full list. Divide one list into two half lists each time, and repeat this step to divide the divided half list, until there is only have one triple in this list.
2. Then if there is only one triple in this list, we need to split this triple into two pairs and return a new list for two pairs.
3. Then do the merge part. Merge two lists into one list each time. For two lists, find the next $x_{i_k}$ between two lists. Compare $y_{i_k}$ with the last past one $y_{i_{k'}-1}$ in another list, choose the bigger $y$. *(there are two situation, see pseudocode)* Add ($x_i$,$y_i$) to the new list X. Repeat this step and find the next $(x,y)$ by choosing the smaller $x_i$ first, add to list X. Until one of these two lists is empty, add all the left element in another list into new list X.

**Pseudocode:**

(1) Merge($a_1, a_2, ..., a_n$):

&emsp; &emsp; &emsp; **// Basic case to split the orignal triples list to pairs list**
(2)&emsp; &emsp; if n == 1:
(3)&emsp; &emsp; &emsp; &emsp; $X$ = [($x_r$, $h$), ($x_l$, 0)]
(4)&emsp; &emsp; &emsp; &emsp; return $X$

&emsp; &emsp; &emsp; ***// Divide and recursive calls***
(5)&emsp; &emsp; m = n/2
(6)&emsp; &emsp; $X_1$ = Merge(First half: $a_1, a_2, ..., a_m$)
(7)&emsp; &emsp; $X_2$ = Merge(Second half: $a_{m+1}, a_{m+2}, ..., a_n$)

&emsp; &emsp; &emsp; ***// Recursive merge section to merge $X_1$ and $X_2$***
(8)&emsp; &emsp; Creat new list $X$
(9)&emsp; &emsp; intial $j$, $i_1$, $i_2$ = 1 represent index for $X$, $X_1$, and $X_2$
(9)&emsp; &emsp; intial flag $a$ that $a$ = 1 or 2 which have smaller $x_{1}$

(10)&emsp;&emsp;while $X_1$ or $X_2$ is not empty:
(11)&emsp;&emsp;&emsp; &emsp; find the small one $x_{i_k}$ between $x_{i_1}$ and $x_{i_2}$. Then  $x_{i_{k'}}$ is another one, 
(13)&emsp;&emsp;&emsp; &emsp; if k == a
(14)&emsp;&emsp;&emsp; &emsp; &emsp; &emsp; $y'_j$ = max($y_{i_k}$, $y_{i_{k'}-1}$) &emsp; &emsp; &emsp; *// compare $y_{i_k}$ with the last past one $y_{i_{k'}-1}$ in another list*
(15)&emsp;&emsp;&emsp; &emsp; &emsp; &emsp; add ($x'_j, y'_j$) to $X$
(16)&emsp;&emsp;&emsp; &emsp; &emsp; &emsp; flag a = k or k', which added
(17)&emsp;&emsp;&emsp; &emsp; if k != a and $y_{i_k}$ > $y_{i_{k'}-1}$
(18)&emsp;&emsp;&emsp; &emsp; &emsp; &emsp; add ($x'_j, y'_j$) to $X$
(19)&emsp;&emsp;&emsp; &emsp; &emsp; &emsp; flag a = k or k', which added
(20)&emsp;&emsp;&emsp; &emsp; $i_k$++, $j$++
(21)&emsp;&emsp;add all the left elements in $X_1$ or $X_2$ into $X$

(22)&emsp;&emsp;return $X$

</br>

Operations to count: add or updata pair ($x'_j, y'_j$) to the list

Base case: lines (2) - (4). The base case here is the data pre-processing to transfer the triples to pairs.
Recursive calls: lines (6) and (7)
Counted operation: line (15) and line (18). These are the progress deal with the overlap section between two lists. Only one of them will happen at every recursive level.

Corresponding recurrence relation:
$$ 
\begin{align*}
    T(n) = 
    \begin{cases}
    2 & \text{for } n = 1 \\
    2T(n/2) + n & \text{otherwise} 
    \end{cases}
\end{align*} 
$$
*\* Notice the size $n$ here is the number of pairs, not number of triples.* 

Where a=2, b=2, c=1, d=2, k=1,


1. "a" stands for the number of problems need to consider after every time divide. There will be two half of the array after every time divide. That is why a = 2.
2. "b" stands for the size after every time divide. In the algorithm, the divide will divide the full array into two half parts, which is n/2 so that is why b = 2.
3. "c" and "k" are both standing for the number of counted operations in one recursive level. It is line (15) or (18). For the worst case. Every $x_i$ in two list need to add to new list X. So the operation number for one recursive level is $n$. there will be only one loop for each n, so k = 1. 
4. "d" is standing for the number of counted operations in the base case. The opearation to count in base case is 2 Therefore d = 2.

$a = b^k$, so the complexity of algorithm is,
$$T(n) = \Theta (n^klogn) = \Theta(nlogn)$$
