#### CSE 417: Homework 3
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou
<br/>

Problem 3:

In the DFS algorithm, a node will found to be a articulation when all edges of a biconnected component which this articulation belongs have been explored.

For example, in problem 1, the time to confirm the node G is a articulation point is by checking the edge (G,B). The G.dfs# = B.LOW#. At this time, the edges explored order are: (C,G) $ \rightarrow $ (G,B) $ \rightarrow $ (B,A) $ \rightarrow $ (A,F) $ \rightarrow $ (F,G). All the edges after (G,B) is  belong to a biconnected component. But this fuction may only works on the biconnected component have one articulation point.

The another situation is the biconnected component with two articulation points. For example, in problem 1,the biconnected component between G and H. All the biconnected components only connected to one of G or G can be found use the method in previous, like the component {(H,D), (D,E), (E,H)} and {(H,J)}. If remove these biconnected component which already be found. The edges left will be the biconnected component between G and H.

So we can add a few simple steps to find biconnected components based on the algorithm for finding articulation points:
1. When a new edge is explored, save it on a list
2. When algorithm find a new articulation point. take out all the explored edges after that. These edges is a biconnected component. 
3. Keep DFS untill we find all the articulation points and take out all the edges to be a biconnected component in batches. (The same edge can be determinde as an articulation point in several times)

For the operation time, it is relative to the algorithm for finding articulation points. This only add one storage and one take out processing per edge. If there are n edges, then the operation time will only increase by 2n.

This algorithm can also find biconnected with two articulation points. Take the graph in question 1 as an example. If DFS is performed from the leftmost point A, when it is found that the G point is the articulation point, all the edges to the right of H have been taken out. What remains in the list is the biconnected component between G and H.

This also works for to biconnected components with root nodes, because this algorithm will consider all root nodes to be an articulation point. If we also want to find all articulation points. We only need to add a determination of the root point in the algorithm to decide whether to put it in the list of articulation points.