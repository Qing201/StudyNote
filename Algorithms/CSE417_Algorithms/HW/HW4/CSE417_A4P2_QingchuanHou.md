#### CSE 417: Homework 4
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou
<br>
##### Problem 2:

(a)

Initially let $X$ be the set of all offices, and let a set $G$ be empty to store the location of hotspots, and set index $j = 0$
While $X$ is not yet empty:
&emsp; &emsp; Choose a office $x_i \in X$ that has the smallest location
&emsp; &emsp; If location $x_i + 100$ is not out of range of corridor:
&emsp; &emsp; &emsp; &emsp; Add a WIFI location $g_j = x_i + 100$ to the set $G$
&emsp; &emsp; Elseif:
&emsp; &emsp; &emsp; &emsp; Add a WIFI location $g_j = x_i$ to the set $G$
&emsp; &emsp; Delete all office $x$ from $X$ that are in the distant range $(x_i, x_i+200)$ &emsp; &emsp; &emsp; &emsp; *Delete all $x$ if out of range*
&emsp; &emsp; j ++
EndWhile
Return the set $G$ as the set of location of hotspots.

In this algorithm, I will first find the office has the smallest location. Then put a hotspot that covered this office at the max range (100 feet). Then find the next uncovered office and put another hotspot using the same method. Repeat this step until all of the offices has been covered.
<br>

(b)

The optimal solution of this problem is let all the hotpots use it longest range (100 feets) and there do not have any office coverd by mutiple hotpots. At this time, the use efficiency of hotspots is the highest.

Take my algorithm as a reference. In all other solutions, no value of $g_j$ can be greater than the values of $g_j$ in my solution, because if increasing the value of $g_j$, there will be alwalys have a $x_i$ in X that is not covered by any hotspot. 

Therefore, in other solutions, there may only be a value of $g_j$ less than my value of $g_j$. But in this case, we can always increase the value of $g_j$ until $g_j-x_i = 100$. This increase will not cause any office to lose WIFI and it will always increase the effective coverage area of all hotspots. So if there are other possible solutions. It can be optimized by increasing a value of $g_j$ within a reasonable range. That will more similar to my algorithm's solution.

*(These analyses do not include the location of the last hotspots which when out of range of corridor in my algorithm. The last one is special, but the above analysis is still correct in general )*


