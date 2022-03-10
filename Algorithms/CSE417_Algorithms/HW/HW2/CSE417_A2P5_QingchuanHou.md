#### CSE 417: Homework 2
<br/>

#### Name: Qingchuan Hou
#### Student ID: 2127437
#### UWNetID: qhou
<br/>

**Problem 5:**

If $G$ is a tree, it will not have Non-tree edges in the graph. In this case, every vertex will only have one possible parent in the tree. If the graph is a connected graph, whatever the BFS tree or DFS tree, there will have one and only one way to find every vertex. Therefore, the $T_B$ will same as $T_D$ and also equal to $E$, which is $G$ itself.

If G is not a tree, whatever in the BFS tree or DFS tree, the trees will always have some non-tree edges in $G$. In the DFS tree, all the non-tree edges never join vertices on the same or adjacent levels but join a vertex and one of its descendants/ancestors. So there will always have a shortcut edge in $G$ that can give a smaller distance for some edges in the DFS tree. But in the BFS tree, the tree-edges are the shortest path for every vertex. Therefore, if $G$ is not a tree, $G \ne E$, $T_B$ will always different with $T_D$.

Thus, $T_B$ = $T_D$ if and only if $T_B$ = $T_D$ = $E$