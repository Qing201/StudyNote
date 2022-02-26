#### CSE 417: Homework 7
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou

</br>

##### Problem 6:

This problem can be seen as a weighted interval scheduling problem. For Econo order, it can be trade as a one week job, where bid $e_i$ has $s_i$ = $i$, $f_i$ = $(i+1)$ For Deluxe bid, it can be trade as a two week job, where bid $d_i$ has $s_i$ = $i-1$, $f_i$ = $(i+1)$. Therefore, we can creat a new list to store the $v_i$, $s_i$, and $f_i$ for each $e_i$ and $b_i$ and deal with it as a weighted interval scheduling problem.

**Pseudocode for dynamic algorithm:**

    // create new lists for weighted interval scheduling problem
    i = 1
    while i <= n:
        // store the values, start time, and finish time
        v(2i-1) = e_i, s(2i-1) = i, f(2i-1) = i+1   //Econo bids
        v(2i) = d_i, s(2i) = i-1, f(2i) = i+1       //Deluxe bids
        i ++

    // dynamic algorithm
    // The job is already sorted because they have been stored in sorted way.
    Compute p(1), p(2), ..., p(3)       // Faster algorithm has been provide in problem 1

    Max-Income():
        MAX[0] = 0
        for j = 1 to 2n:
            MAX[j] = max(v(j)+MAX[p(j)], MAX[j-1])
    
    Output MAX[n]

This algorithm will give the max income value for every week. Then we can use the traceback algorithm to find with bid has been selected.

One thing need to notice is, the odd $i$ in the new list is the economy bid, and the even $i$ in the new list is the deluxe bid. Therefore, we can determine what bid $v_i$ is by cheking $i$ is odd or even. Also, the new list has been store in sequence, so we can easily find which week the bid is.

**Pseudocode for traceback:**

    Initall list X and Y with number n of 0 to store x and y
    Find-Solution(j):
        if j==0:
            output None
        elif (v(j) + MAX[p(j)] > MAX[j-1])
            // check where v(j) belong to 
            if j is odd, x((j+1)/2) = 1
            if j is even, y(j/2) = 1
            Find-Solution(p(j))
        else
            Find-Solution(p(j-1))

The list X and Y will have the $x_i$ and $y_i$ to show which bid has been selected.

**Run time:**
In the dynamic algorithm, we need store a new list, the run time here is $O(2n)$, then to cacluate the MAX() for each jobs. The total job number is 2n, so the run time here is O(2n). In the traceback algorithm, each bid will go through once in the worst case, so the run time is $O(2n)$, Therefore, the total run time is: 
$$ O(2n) + O(2n) +O(2n) = O(n)$$