#### CSE 417: Homework 7
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 4:

First, we need to find the max profit from a subset of items with a weight limit $W$, which is OPT [$n$, $W$].

The different between this algorithm, which items can be repeat, with the problem cannot have repeat items is: When $w_i \leq w$, max function compear OPT [$i$-1, $w$] with ($v_i$ + OPT [$i$, $w-w_i$]). compare with $w-w_i$' OPT in the same line, not the last previous line. So this item can be added multiple times.

**Pseudocode:**
for $w$ = 0 to $W$
&emsp; &emsp;   OPT[0, $w$] = 0

for $i$ = 1 to $n$
&emsp; &emsp;    for $w$ = 1 to $W$
&emsp; &emsp; &emsp; &emsp;        if w$_i$ > w
&emsp; &emsp; &emsp; &emsp; &emsp; &emsp;            OPT [$i$, $w$] = OPT [$i$-1, $w$]
&emsp; &emsp; &emsp; &emsp;        else
&emsp; &emsp; &emsp;  &emsp; &emsp; &emsp;            OPT [$i$, $w$] = max { OPT [$i$-1, $w$], $v_i$ + OPT [$i$, $w-w_i$] }

return OPT [$n$, $W$]

</br>

The question here is find how many of each item to carry. Therefore, after find the max profit, we can use backtrack to find which item and the number of items has been added.

**The traceback algorithm is :**
Create a zeros list to store number of items $m$

Find-Solution( OPT(n, W) ):
&emsp; &emsp;   if OPT(n, W) == 0:
&emsp; &emsp; &emsp; &emsp;        return None
&emsp; &emsp;     elif OPT(n, W) > OPT(n-1, W):
&emsp; &emsp;  &emsp; &emsp;        $m_n$ += 1
  &emsp; &emsp;  &emsp; &emsp;        Find-Solution( OPT(n, W-$w_n$) )
  &emsp; &emsp;    else:
  &emsp; &emsp;  &emsp; &emsp;        Find-Solution( OPT(n-1, W) )
return list $m$

</br>

The number in list are the number of items.

The run time for first dynamic algorithm is $O(nW)$, and the run time for second tracebacke algorithm is O(n+W). The total run time is $O(nW)$.