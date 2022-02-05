#### CSE 417: Homework 4
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou
<br/>

Problem 1:

Here is a counter example:
If there have four tasks between time $t_0 - t_1$, The four tasks and the optimal solution is shown below:
![optimal](Image/A4P1_optimal.png)
<br>
If we use the greedy algorithm for interval by choosing the task which has the smallest finishing time first, then add a new color if there don't have enough time on the existed colors. The solution will be:
![solution1](Image/A4P1_greedy.jpeg)
This greedy algorithm will choose the smallest finishing time first. The task A has the earliest finishing time, so it will arranging task A in color 1. Then the C will be removed because it oberleaps with task A. Between task B and task D, the task D has a earlier finishing time rather than task B. Therefore, the algorithms will choose task D instead of task B. Then every remaining task overlaps the tasks in orange color, the algorithm will add a new color blue, and assign task C first. But task B overlaps all the tasks in the colors orange and blue. Therefore, the algorithm needs add a new third color to assign task B.
<br>
This algorithm has three colors and the optimal one only has two colors. It is obviously the second arrangement use greedy algorithm by choosing the earliest finishiing time first is not the optimal solution in this case.