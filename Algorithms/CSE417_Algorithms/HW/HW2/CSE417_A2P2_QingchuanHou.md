##### CSE 417: Homework 2
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou
<br/>

Problem 2:


<p align="center">
    <img src="image/BFS.png" alt="drawing" width="300"/>

There are other 3 different spanning tree are possible. The only difference these 4 tress in the edges bettween vertex {8, 9, 10, 12, 13}. There 5 trees are:
1. 8-12, 8-13 (Showing on the picture)
2. 8-13, 9-12
3. 9-12, 10-13
4. 8-12, 10-13

** Added in redo **
How each spaning tree arises:
These different spanning trees are caused by the searching sequence between nodes 8, 9, and 10.
If a node has mutilple edges with the nodes in uper level. The parant of this node in BFS tree will decide by which node in uper level doing the search first.
1. If search node 8 first, the node 12, 13 will be children of node 8.
2. If search sequence is 9 -> 8 -> 10, the node 12 will be 9's children, the node 13 will be 8's children, the edges will be 8-13, 9-12
3. If search sequence is 9 -> 10 -> 8 or 10 -> 9 -> 8, the edges will be 9-12 and 10-13.
4. If search sequence is 10 -> 8 -> 9, the edges will be 10-13 and 8-12.
**

When use the BFS, if there have any edges between two different levels in the graph haven't been used in a BFS tree *(the broken line in the graph)*. That means there have differents spanning trees are also possible. *(If does not specify the order)* Because these egdes can replace a edges without change the level of every nodes.

The number of different trees is decided by the number of cross-level-edges for each nodes in deeper level. The number of differents trees is the product of these number of cross-level-edges for each nodes in deeper level. 

In this graph. There are un-used edges betwwen level 3 and 4. In deeper level, which is level 4, the nodes 13 and 12 both have 2 cross-level-edges. So the number of different spanning tree for BFS is: $2 \times 2 = 4$