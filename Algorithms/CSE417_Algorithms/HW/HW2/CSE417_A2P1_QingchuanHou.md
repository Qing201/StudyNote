#### CSE 417: Homework 2
#### Name: Qingchuan Hou
#### Student ID: 2127437
#### UWNetID: qhou
<br/>

Problem 1:
(1) In the SMP problem, every $m$ can only have one $w$. For evey unpaired $m$, we check evey $w$ by $m$'s prefered sequence. If $w$ is not paired, match $(m,w)$, if $m$ is paired, check if $m$ prefer $w$ rather than $w'$ in pair $(m,w')$. if so, match $(m,w)$ and delete $(m,w')$. $a_i$ will be unpaired again. if not, search $m$'s next prefered $w$.
But in the S5PSTTP problem, every coach($c$) can pair with 5 athletes($a$). Here is the way to using SMP probelm as inside processing of S5PSTTP. We can consider every coach's preference first. For $f(x)$ we can mark as $c$ is 'unpaired' if pairs of $c$ is less than 5. If $c$ already has 5 pairs, we can use the $c$'s least prefered $a'$ in exsit pair as the compare pair $(a,c')$ to $c$ in SMP.

(2) In this algorithm, it will check if exist pair is less than 5, and store the matched pair at least. Therefore, after processing the steps described before, every $c$ will have 5 stable matched pairs $(c,a_i)$. This $c$ and 5 $a$ will be a team. In the code, we can create a dictionary list. Store every $c$ as a key and have 5 $a$ for each key. Evey key with its 5 elements will be a team.

(3) In this algorithm, for every unpaired $a$ it will checking every $c$'s least prefered $a'$ in exsit pair as the compare pair $(a,c')$. Because the $a'$ is the least prefered of $a$, if pair $(a,c')$ is statble, the other pair of $c$ will also be stable. and if it is not stable, the new $a$ will replace this pair. So after these processing, all the unstable pair will be replaced, and will keep all the stable pairs. So this algrithm is correct.

Runtime analysis:
For every unpaired $a$, it need to compared with every a least not prefred pair $(c,a')$ for every $c$, so the compared time is number of $a$ times number of $c$, which is $5n \times n$. Tre run time here will be $O(n^2$. However, if a pair has been replaced, the $a'$ which has been replaced will become a new unpired $a$. Therefore, the run time need $O(n^2)$ or more.