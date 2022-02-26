#### CSE 417: Homework 7
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 3:

$w_1$ = 5, &emsp; $w_2$ = 2, &emsp; $w_4$ = 4, &emsp; $w_3$ = 3, &emsp; $w_5$ = 6

i\W | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16
- | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - 
0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
1(5) | 0 | 0 | 0 | 0 | 0 | 5 | 5 | 5 | 5 | 5 | 5 | 5 | 5 | 5 | 5 | 5 | 5 | 5 
2(2) | 0 | 0 | 2 | 2 | 2 | 5 | 5 | 7 | 7 | 7 | 7 | 7 | 7 | 7 | 7 | 7 | 7 | 7 
3(4) | 0 | 0 | 2 | 2 | 4 | 5 | 6 | 7 | 7 | 9 | 9 | 11 | 11 | 11 | 11 | 11 | 11 | 11 
3(3) | 0 | 0 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 12 | 14 | 14 | 14 | 14 
5(6) | 0 | 0 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 

</br>

The traceback algorthm is :
Find-Solution( OPT(n, W) ):
&emsp; &emsp;   if OPT(n, W) == 0:
&emsp; &emsp; &emsp; &emsp;        return None
 &emsp; &emsp;     elif OPT(n, W) > OPT(n-1, W):
  &emsp; &emsp;  &emsp; &emsp;        print $w_n$
  &emsp; &emsp;  &emsp; &emsp;        Find-Solution( OPT(n-1, W-$w_n$) )
  &emsp; &emsp;    else:
  &emsp; &emsp;  &emsp; &emsp;        Find-Solution( OPT(n-1, W) )

</br>

</br>

</br>
</br>

</br>

</br>

</br>

For example W = 16:
1. OPT(5, 16) = 16 > 14 = OPT(4, 16):  &emsp; $w_5$ = 6 is solution
2. OPT(5-1, 16-6) = 10 > 9 = OPT(3, 10):  &emsp; $w_4$ = 3 is solution
3. OPT(4-1, 10-3) = 7 = 7 = OPT(2, 7):  &emsp; go tot OPT(2, 7)
4. OPT(2, 7) = 7 > 5 = OPT(1, 7):  &emsp; $w_2$ = 2 is solution
5. OPT(2-1, 7-2) = 5 > 0 = OPT(0, 5):  &emsp; $w_1$ = 5 is solution
6. OPT(0, 5-5) = 0:  &emsp; return nothing
   
So the solution for W = 16 will be: $w_1$, $w_2$, $w_4$, $w_5$