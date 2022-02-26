#### CSE 417: Homework 7
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 1:


**Pseudocode:**

Sort the list by the end time and store in $L$

For each job $L(j)$:
&emsp; &emsp; using binary search to find the capble job $L[i]$ with latest finsh time, where $f_i < s_j$
&emsp; &emsp; $p[j] = i + 1$ &emsp; &emsp; &emsp; &emsp; // $i$ is index, start with 0 

</br>

This algorithm will works because the job has been sorted by end time. So, if a job $L(i)$'s finish time is small than job $L(j)$'s start time, then for any job $L(k)$ where $k < j$, they all have a small finish time than job $L(i)$. So they are all capable of job $L(j)$. Therefore the index of latest job $L(i)$ will represent the job $L(j)$'s $p_j$.
</br>

**Run time:**
In this algorithm, the sort step will cost $O(nlogn)$. Then, for each job, do the binary search to find the capable job $L[i]$ with the latest finish time. The runtime of binary search is $O(logn)$, and there is $n$ number of jobs, so the total run time here is $O(n*logn)$. Therefore, the total run time is:
$$O(nlogn) + O(nlogn) = O(nlogn)$$
which is faster than $O(n^2)$