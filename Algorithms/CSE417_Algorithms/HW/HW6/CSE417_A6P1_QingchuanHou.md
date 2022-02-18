#### CSE 417: Homework 6
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 1:
$$
\begin{align*}
& T(n) = d    \; & \text{for} \ n<b \\
& T(n) = a T(n/b) + cn^k \; & \text{for} \ n \ge b \\
\end{align*}
$$

For this problem, $a = 3$, $b = 3$, $d =0$, $ c = c$ in problem and $k = 1$

Because $a = b$, for $n \ge b$,
$$ T(n) = \Theta (n^klogn) $$
For this problem,
$$ T(n) = \Theta (n\ logn)$$
