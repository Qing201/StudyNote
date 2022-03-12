#### CSE 417: Homework 9
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 4:

**(a)**
**1) Hint:** $V$'s two (nonempty, nonoverlapping) subset $V_1$ and $V_2$ that the element in $V_1$ have k number of edges with elements in $V_2$

**2) Length:** Number of all elements in two subset

**3) Verifier:** Syntax + Satisfies
1. check $V_1$ and $V_2$ are two (nonempty, nonoverlapping) subset of $V$. 
2. Search every nodes in $V_1$ count how many connection with nodes in $V_2$, check if it ≥ k.

If these two subsets $V_1$ and $V_2$ are two (nonempty, nonoverlapping) subsets of $V$, and there are k number of edges that have one end in $V_1$ and another in $V_2$. This case will return a 'yes'.

If these two subsets $V_1$ and $V_2$ are not two (nonempty, nonoverlapping) subsets of $V$, or there is less than k number of edges have one end in $V_1$ and another in $V_2$. This instance will not pass the verifier because not satisfy for MaxCut problem

**4) Runtime:**
To check the $V_1$ and $V_2$ are two (nonempty, nonoverlapping) subsets of $V$ will only take $O(n)$ time. To verify the number of connections, check every element in $V_1$ with every element in $V_2$ if there is an edge, and count the number of existing edges. The runtime for this is $O(n^2)$. The total time takes to run the verifier is :
$$O(n^2) + O(n) = O(n^2)$$
It is a polynomial time.



**(b)**
This MaxCut problem is given an undirected graph G = (V,E) and an integer k, so we need to verify every possible subset if there have k edges.

**Pseudocode:**

    k = satisfying edges number 

    // Split the V into two subset V_1 and V_2
    for i = 1 to n/2 :
        select i number of element in V_1 and rest in V_2
        for every possible two split subset:
            result = Verifier()
            if result = 'yes':
                return 'yes'
                break
            else:
                continue
    return 'no'

    Verifier():
        // Using the verifier to check if it is satisfyed for this MaxCut problem
        i = 0
        for every elements x in V_1:
            for every elements y in V_2:
                if there is an edge (x,y) in graph G
                i ++
        if i >= k:
            return 'yes'
        else:
            return 'unconvinced'

**Correctness Analysis:** 
This algorithm will go through every possible subset $V_1$ and $V_2$, and count the number of satisfying edges, verifier if this subset is satisfied to the MaxCut problem. If it found a satisfying subset, will return 'yes' and stop the search. If not will go through the next possible subsets. It will return 'no' if no subset is satisfied.

**Run Time:**
When split the subset $V_1$ and $V_2$, the total number of possible option is:
$$ \sum^n_{k=1} \begin{pmatrix} n \\ k \end{pmatrix} = 2^n-1$$
The runtime for verifier section is $O(n^2)$. It is much smaller than exponential time. Therefore, the total runtime is:
$$O(2^n)$$