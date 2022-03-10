##### CSE 417: Homework 2
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou
<br/>

**Problem 6:**
The idea for this problem is to use DFS for every image with judgments, the image will be the vertices and the judgments will be the edges. Use BFS to go through the images by existing judgments. When finding a new image, label the new image to a group according to the judgments with the previous image. If the connected image already has a label, compare the label with judgments. If correct, compare with next. If incorrect, return the result inconsistent. If all is correct, return result consistent.

**Pseudocode:**

    initial state: all image "g_1, g_2, ... g_n" undiscovered  
    initial result = consistent      

    for i = 1 to n:                     // deal with unconnected graph
        if state g_i is undiscovered: 
            mark g_i discovered
            Search(g_i):
                if have judgments then
                    for other g_j have judgements with g_i

                        if g_j undiscovered:
                            if judgment is 'same':
                                label same image label(P or R)
                            if judgment is 'different':
                                label different image label(P or R)
                            mark g_j discovered
                            result = Search(g_j)         // BFS for next connected vertex

                        if g_j discovered:
                            if label is not correct with judgement: 
                                result =  inconsistent    
                                
            if result is 'inconsistent' break the for loop and return result
            else continue
    output result
    
**Correctness Analysis:**        
In this algorithm, the result returned will be 'consistent' or 'inconsistent'. I initial the result to consistent and doing the BFS. If find an incorrect judgment, it will change the result to 'inconsistent' and output it. Otherwise, the initial result will not change and output 'consistent'.

**Run time:**
This algorithm will search every image can compare it with every judgment have this image. Every judgment will include two images, so each judgment will be touched twice, once from each end. Therefore the runtime is $O(m+n)$