#### CSE 417: Homework 7
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 2:

$j$ | $p_j$ | $v_j$ | max() | opt($j$) | solution($j$) 
- | - | - | - | - | -
0 | - | - | - | 0 | -
1 | 0 | 25 | max(25+0, 0) | 25 | 1 
2 | 0 | 20 | max(20+0, 25) | 25 | 1 
3 | 0 | 31 | max(31+0, 25) | 31 | 3 
4 | 0 | 40 | max(40+0, 25) | 40 | 4 
5 | 1 | 35 | max(35+25, 40) | 60 | 5,1 
6 | 3 | 28 | max(28+31, 60) | 60 | opt(5) -> 5,1 

(e) if $v_6 = 30$, the max() will be changed to max(30+31, 60), where 61 > 60. Therefore, when trackback, the algorithm will choice $j$=6 then backtrack($j$=3) *(where $p_j$ = 3)*. Then backtrack($j$=3) will give $j$=3 and 0. 
Therefore, the solution will change to 6, 3.
