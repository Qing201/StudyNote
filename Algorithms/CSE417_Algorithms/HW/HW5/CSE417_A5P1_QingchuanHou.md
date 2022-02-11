#### CSE 417: Homework 5

##### Name: Qingchuan Hou

##### Student ID: 2127437

##### UWNetID: qhou

</br>

##### Problem 1

For example, if There is a list $N$, which has n points $n_i$ in a 2 dimensional coordinate. $i \in (1,n) $.
If i is odd number: $n_i = (i,0)$
If i is even number: $n_i = (i,a)$, which $a = \infty$

In this case, in 2 dimensions, it is obvious that the distance between any $n_i$ and $n_{i+2}$ is the shortest, which is 2.

In this case, if we only sort this array by x-coordinate and ignore the y-coordinate in each point, we will have $n_i = i$. The shortest distance will be the distance between any point $n_i$ and $n_{i+1}$ which is 1. But the true distance between any $n_i$ and $n_{i+1}$ in 2d is $\sqrt{1^2 + a^2}$, which is infinity.

The pair $n_i$ and $n_{i+1}$ is the closest pair in x-coordinate, but it is not the closest pair in really 2-d.
