#### CSE 417: Homework 6
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 2:
![](Image/P1-2.png)

In this case, the recursion tree is:
| Level | Num | Size | Work |
| - | - | - | - |
| 0 | 1 = 3$^0$ | n | cn | 
| ... | ... | ... | ... |
| $i$ | 3$^i$ | n/3$^i$ | 3$^i$ c n/3$^i$ |
| ... | ... | ... | ... |
| $k$ | 3$^k$ | n/3$^k$ = 1 | 3$^k$ $T(1)$ |

n = 3$^k$, k = log$_3$n

$\begin{aligned}
    T(n) & = \sum ^k_{i=0} 3^i cn/3^i \\
         & = cn \ (1+k) \\
         & = cn \ (1 + log_3n) \\
         & = O(nlogn)
\end{aligned}$