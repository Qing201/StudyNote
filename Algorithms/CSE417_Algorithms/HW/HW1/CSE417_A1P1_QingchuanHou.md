#### CSE 417: Homework 1
<br/>

#### Name: Qingchuan Hou
#### Student ID: 2127437
#### UWNetID: qhou
<br/>

Problem 1:
Briefly explain (if true) or give a counterexample (if false): In every instance of the Stable Matching Problem, there is a stable matching containing a pair $(m, w)$ such that $m$ is $w$’s first choice and $w$ is $m$’s first choice.

**False**

For example, if we have two set M and W. There are two elements in M set: {m1,m2}, and there are two elements in W set: {w1,w2}. There preference are:

<center>
<table>
<tr><th>M's Preference</th><th>W's Preference</th></tr>
<tr><td>

| Set M | 1st | 2nd |
|-------|-----|-----|
| m1    | w1  | w2  |
| m2    | w2  | w1  |

</td><td>

| Set W | 1st | 2nd |
|-------|-----|-----|
| w1    | m2  | m1  |
| w2    | m1  | m2  |

</td></tr> 
</table>
</center>

In this sample, the stable matching pairs could be $(m1,w1)$, $(m2,w2)$. In this case the $m1$'s first choice is $w1$, but $w1$'s first choice is $m2$. Also,the $m2$'s first choice is $w2$, but $w2$'s first choice is $m1$. 

** Added in redo **
There are two case in this problem. The another stable matching pairs is $(m1,w2)$, $(m2,w1)$. In this case the $w1$'s first choice is $m2$, but $m2$'s first choice is $w1$. Also, $w2$'s first choice is $m1$, but the $m2$'s first choice is $w2$.

Therefore, the statement is false.
