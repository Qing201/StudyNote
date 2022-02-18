#### CSE 417: Homework 6
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 4:
The divide and conquer algorithm for this problem have two-part, the divide part and conquer part. 
1. First, we need to divide the full list. Divide one list into two half lists each time, and repeat this step to divide the divided half list, until there is only have one triple in this list.
2. Then if there is only one triple in this list, we need to split this triple into some pairs for future operations, and return a new list for these pairs.
3. Then do the merge part. Merge two lists in to one list each time, find the overlap section for two lists, compare the $y_i$ in two lists for each $x_i$ and find bigger $y_i$. Then store every $(x_i, y_i)$ in new list $X$ with bigger $y_i$. In the other not overlap section, store the original pairs in two lists to the new list $X$. Then merge this list $X$ with another merged list $X'$ to get another new pairs list. Repeat this step until all lists have been merged into one list. Which is the final result.

**Pseudocode:**
(1) Sort list $A$ by the small $x_l$ first

(2) Merge($a_1, a_2, ..., a_n$):

&emsp;&emsp; &emsp; *// Basic case to split the orignal triples list to pairs list*
(3)&emsp;&emsp; if n == 1:
(4)&emsp;&emsp; &emsp; &emsp; $X$ = all $(x_i, y_i)$ for $x_i$ in range $a_1[x_r]$ to $a_1[x_l]$, and $y_i = a_1[h]$
(5)&emsp; &emsp; &emsp; &emsp; return $X$

&emsp; &emsp;&emsp; // Divide and recursive calls
(6)&emsp;&emsp; m = n/2
(7)&emsp;&emsp; $X_1$ = Merge(First half: $a_1, a_2, ..., a_m$)
(8)&emsp;&emsp; $X_2$ = Merge(Second half: $a_{m+1}, a_{m+2}, ..., a_n$)

&emsp; &emsp;&emsp; *// Recursive merge section to merge $X_1$ and $X_2$*
(9)&emsp;&emsp; if $X_1[x_r] < X_2[x_r]$ 
(10)&emsp;&emsp; &emsp;&emsp;if $X_1[x_l] < X_2[x_r]$ &emsp; &emsp; &emsp; &emsp; // no overlap,
(11)&emsp;&emsp;&emsp;&emsp; &emsp; &emsp; $X = X_1 \cup X_2$, and fill 0 between $X_1[x_r]$ and $X_2[x_r]$ 

(12)&emsp;&emsp;&emsp;&emsp; if $X_1[x_l] > X_2[x_r]$ &emsp; &emsp; &emsp; &emsp; // $X_2[x_r]$ to $X_1[x_l]$ is overlap
(13)&emsp;&emsp;&emsp;&emsp; &emsp; &emsp; for $x_i < X_2[x_r]$, $X[(x_i, y_i)] = X_1[(x_i, y_i)]$
(14)&emsp;&emsp;&emsp;&emsp; &emsp; &emsp; for $x_i > X_1[x_l]$, $X[(x_i, y_i)] = X_2[(x_i, y_i)]$
(15)&emsp;&emsp;&emsp;&emsp; &emsp; &emsp; otherwise: overlap section, $X[(x_i, y_i)] = (x_i, y_i)$, 
&emsp;&emsp;&emsp;&emsp; &emsp; &emsp; &emsp;&emsp;&emsp;&emsp; &emsp; &emsp; &emsp;where $y_i$ = max($X_1[y_i],X_2[y_i]$ )

(16)&emsp;&emsp;if $X_1[x_r] > X_2[x_r]$ &emsp; &emsp; &emsp; &emsp; &emsp; &emsp;// $X_2[x_l]$ to $X_2[x_r]$ is overlap
(17)&emsp;&emsp;&emsp;&emsp; for $x_i$ in $X_2$, overlap section, $X[(x_i, y_i)] = (x_i, y_i)$, 
&emsp;&emsp;&emsp;&emsp; &emsp; &emsp; &emsp;&emsp;&emsp;&emsp; &emsp; &emsp;where $y_i$ = max($X_1[y_i],X_2[y_i]$)
(18)&emsp;&emsp;&emsp;&emsp; otherwise, $X[(x_i, y_i)] = X_1[(x_i, y_i)]$

(19)&emsp;&emsp;return $X$

</br>

Operations to count: the value comparison between $y_i$

Base case: lines (3) - (5). The base case here is the data pre-processing to transfer the triples to pairs.
Recursive calls: lines (7) and (8)
Counted operation: line (15) and line (18). These are the progress deal with the overlap section between two lists. Only one of them will happen at every recursive level.

Corresponding recurrence relation:
$$ 
\begin{align*}
    T(n) = 
    \begin{cases}
    0 & \text{for } n = 1 \\
    2T(n/2) + n & \text{otherwise} 
    \end{cases}
\end{align*} 
$$
*\* Notice the size $n$ here is the number of pairs, not number of triples.* 
The problem assume the total n is power of 2, so do not need to consider if n = 0

Where a=1, b=2, c=1, d=2, k=1,


1. "a" stands for the number of problems need to consider after every time divide. There will be two half of the array after every time divide. That is why a = 2.
2. "b" stands for the size after every time divide. In the algorithm, the divide will divide the full array into two half parts, which is n/2 so that is why b = 2.
3. "c" and "k" are both standing for the number of counted operations in one recursive level. Every recursive level may have some comparisons to deal with the overlap section, line (15) or (18). c is a decided by what is the triples look like. The worst case is the whole list is overlaped. However, there will be only one loop for each n, so k = 1. 
4. "d" is standing for the number of counted operations in the base case. Because in this situation, the opearation to count is the value comparison between $y_i$, and there is no such of this comparison in base case. The base case is the data pre-processing to transfer the triples to pairs. Therefore d = 0.

$a = b^k$, so the complexity of algorithm is,
$$T(n) = \Theta (n^klogn) = \Theta(nlogn)$$
