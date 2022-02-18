#### CSE 417: Homework 6
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 5:
$$2142 * 1233 = \\
a * 10^4 + (-a + b -c) * 10^2 + c$$

$ a = 21 * 12 $
$ b = (21 + 42) * (12 + 33) = 63 * 45$
$ c = 42 * 33 $

</br>

For each a, b, and c, we can still using Karatsuba-like algorithm

</br>
(1)

$$a = 21 * 12 = \\
a_a * 10^2 + (-a_a + b_a - c_a) * 10^1 + c_a $$

$ a_a = 2 * 1 = 2 $
$ b_a = (2 + 1) * (1 + 2) = 9$
$ c_a = 1 * 2 = 2 $
Therefore,
$$a = 2 * 10^2 + (-2 + 4 - 2) * 10^1 + 2 \\
= 252 $$

</br>
(2)

$$b = 63 * 45 = \\
a_b * 10^2 + (-a_b + b_b - c_b) * 10^1 + c_b $$

$ a_b = 6 * 4 = 24 $
$ b_b = (6 + 3) * (4 + 5) = 81$
$ c_b = 5 * 3 = 15 $
Therefore,
$$b = 24 * 10^2 + (-24 + 81 - 15) * 10^1 + 15 \\
= 2835 $$

</br>
(3)

$$c = 42 * 33 = \\
a_c * 10^2 + (-a_c + b_c - c_c) * 10^1 + c_c $$

$ a_c = 4 * 3 = 12 $
$ b_c = (4 + 2) * (3 + 3) = 36$
$ c_c = 2 * 3 = 6 $
Therefore,
$$c = 12 * 10^2 + (-12 + 36 - 6) * 10^1 + 6 \\
= 1386 $$

</br>

Then, we can apply a, b, and c to the orginal problem $2142 * 1233$:

$$
\begin{align*}
    2142 * 1233 & = a * 10^4 + (-a + b -c) * 10^2 + c \\
                & = 252 * 10^4 + (-252 + 2835 - 1386) * 10^2 + 1386 \\
                & = 2641086
\end{align*}$$

</br>

In this problem, the total "base case" multiplies are $a_a, a_b, a_c, b_a, b_b, b_c, c_a, c_b, c_c$. The total number of "base case" multiplies is 9.