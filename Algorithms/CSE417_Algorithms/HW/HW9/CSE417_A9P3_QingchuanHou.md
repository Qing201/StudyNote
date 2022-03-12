#### CSE 417: Homework 9
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 3:

<center>

| || $x_1$ | $x_2$ | $x_3$ | $x_4$ | | $(x_1 ∨ x_2 ∨ x_4)$ | $(x_1 ∨ ¬x_2 ∨ x_3)$ | $(x_2 ∨ ¬x_3 ∨ ¬x_4)$ |
|:-:|:-:| :-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|||||||||||
| $w_1(x_1)$ || 1| 0 | 0 | 0 || 1 | 1 | - |
| $w_2(¬x_1)$ || 1 | 0 | 0 | 0 || 0 | 0 | - |
| $w_3(x_2)$ || | 1 | 0 | 0 || 1 | 0 | 1 |
| $w_4(¬x_2)$ || | 1 | 0 | 0 || 0 | 1 | 0 |
| $w_5(x_3)$ || | | 1 | 0 || - | 1 | 0 |
| $w_6(¬x_3)$ || | | 1 | 0 || - | 0 | 1 |
| $w_7(x_4)$ || | | | 1 || 1 | - | 0 |
| $w_8(¬x_4)$ || | | | 1 || 0 | - | 1 |
||||||||||| 
| $w_9(s_{11})$ || | | | || 1 | 0 | 0 |
| $w_{10}(s_{12})$ || | | | || 1 | 0 | 0 |
| $w_{11}(s_{21})$ || | | | ||  | 1 | 0 |
| $w_{12}(s_{22})$ || | | | ||  | 1 | 0 |
| $w_{13}(s_{31})$ || | | | ||  |  | 1 |
| $w_{14}(s_{32})$ || | | | ||  |  | 1 |
|||||||||||
| C || 1 | 1 | 1 | 1 || 3 | 3 | 3 |

</center>
</br>
</br>
</br>

There are 4 subsets correspond to the assignment $x_2 = x_3 = F alse$, $x_1 = x_4 = True$. The difference is because the choice of Slack is different. 
1. $w_1 + w_4 + w_6 + w_7 + w_{9} + w_{11} + w_{13} + w_{14}$
   $x_1 + ¬x_2 + ¬x_3 + x_4 + s_{11} + s_{21} + s_{31} + s_{32}$
   </br>
2. $w_1 + w_4 + w_6 + w_7 + w_{9} + w_{12} + w_{13} + w_{14}$
   $x_1 + ¬x_2 + ¬x_3 + x_4 + s_{11} + s_{22} + s_{31} + s_{32}$
   </br>
3. $w_1 + w_4 + w_6 + w_7 + w_{10} + w_{11} + w_{13} + w_{14}$
   $x_1 + ¬x_2 + ¬x_3 + x_4 + s_{12} + s_{21} + s_{31} + s_{32}$
   </br>
4. $w_1 + w_4 + w_6 + w_7 + w_{10} + w_{12} + w_{13} + w_{14}$
   $x_1 + ¬x_2 + ¬x_3 + x_4 + s_{12} + s_{22} + s_{31} + s_{32}$

The assignment of any of them are $x_2 = x_3 = F alse$, $x_1 = x_4 = True$, for this assignment:
$k_1 = x_1 ∨ x_2 ∨ x_4 = True$, because $x_1 = True$
$k_2 = x_1 ∨ ¬x_2 ∨ x_3 = True$, because $¬x_2 = True$
$k_3 = x_2 ∨ ¬x_3 ∨ ¬x_4 = True$, because $¬x_3 = True$

Therefore,
$$ k_1 ∧ k_2 ∧ k_3 = True$$

This assignment is satisfy the Boolean formula.