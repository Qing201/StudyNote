#### CSE 417: Homework 4
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou
<br>

##### Problem 3:

(a)

Sort intervals by start time so $s_1 \le s_2 \le ... \le s_n$, 
d <- 0

for lectures j = 1 to n {
&emsp; &emsp; set a new room label r = 1
&emsp; &emsp; for classrooms k = 1 to d {
&emsp; &emsp; &emsp; &emsp; if last lecture's finishing time $f'_k$ < $s_j$
&emsp; &emsp; &emsp; &emsp; &emsp; &emsp; add lecture j in classroom set $C_k$
&emsp; &emsp; &emsp; &emsp; &emsp; &emsp; $f'_k$ <-- $f_j$, change the last lecture's finnishing time for classroom k to 
&emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; the lecture j's finishing time $f_j$
&emsp; &emsp; &emsp; &emsp; &emsp; &emsp; r = 0
&emsp; &emsp; &emsp; &emsp; &emsp; &emsp; Beak the classrooms searching for loop
&emsp; &emsp; }
&emsp; &emsp; if r = 1
&emsp; &emsp; &emsp; &emsp; d++
&emsp; &emsp; &emsp; &emsp; make a new set $C_d$ for a new classroom $d$
&emsp; &emsp; &emsp; &emsp; add lecture j in classroom set $C_d$
&emsp; &emsp; &emsp; &emsp; store the lecture j's finishing time $f_j$ in $f'_d$
}

<br>

(b)
The worst case for this algorithm is every lecture is overlap with others. 
In this case, every lecture need a new classroom. But before the algorithm assign a new classroom to a lecture, it need compare all the lectures added before. Then creat a new classroom list and assign the lecture in this classroom.
For the $i$'s sorted lecture, this lecture i will compare all the lectures before, which are $i-1$ number of lectures. So the total run time of this algorithm will be 

$$
\begin{align*}
& a \times (1 + 2 + ... + (n-1)) \\
=& a \times \frac{n(n-1)}{2}
\end{align*}
$$

where a is a constant for the steps to assign lecture to the classroom. 

In this case, no matter what n is, the lower bound of this algorithm will be $\Omega (n^2)$

<br>

(c)
