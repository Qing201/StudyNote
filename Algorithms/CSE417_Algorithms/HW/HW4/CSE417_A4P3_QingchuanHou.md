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
The basic idea is: when I have an empty classroom. Using binary search algorithm to search all the sorted lectures to find the easiest capable lecture in this classroom. Then repeat this step, still use a binary search algorithm to search all the sorted lectures to find the next earliest one which start time is after 1st lecture's end time. Repeat this step until this classroom is full and no lecture can be scheduled in this classroom. Then open a new classroom and repeat the steps above.

**Algorithm:**
Sort intervals by start time so $s_1 \le s_2 \le ... \le s_n$, and store all lecture in a list A
$j$ <-- 1
Creat a list $C_1$ as a classroom 


While the list A is not empty
&emsp; &emsp; Using binary search algorithm to search all the sorted lectures to find 
&emsp; &emsp; &emsp; the easiest capable lecture $L_i$
&emsp; &emsp; if find $L_i$, store in the $C_j$ and remove it from list A
&emsp; &emsp; if cannot find, j++ and open a new classroom list $C_j$
Endwhile

In this loop, the complex for binary search is $O(logn)$, and every time find a lecture will cost one binary search, which run time will be $O(nlogn)$. If no capble lecturen for the current classroom, it will add a new classroom. Every time add a new classrom, will have one extrol binary search. Even the worst case, every lecture need a new room, the run time for this worst case is $O(nlogn+n)$, which lecture number is equal to classroom number. It is still $O(nlogn)$