#### CSE 417: Homework 1 
<br/>

#### Name: Qingchuan Hou
#### Student ID: 2127437
#### UWNetID: qhou
<br/>

Problem 5:
Arrange the following six function in order of non-decreasing growth rate; i.e., $f_i$ may precede $f_j$ only if$f_i =O(f_j)$.

a) $ f_1(n) = n ^{2.5} $

b) $ f_2(n) = \sqrt{2n} $

c) $ f_3(n) = n + 10 $

d) $ f_4(n) = 10^n $

e) $ f_5(n) = 100^n $

f) $ f_6(n) = n^2 log_2 n $

<br>

In general, when $ n \ge 1$, the growth rate of therr function is : $log_an \le n^a \le a^n$,

Therefore,
$$f_2(n) \le  f_3(n) \le f_6(n) \le f_1(n) \le f_4(n) \le f_5(n) $$