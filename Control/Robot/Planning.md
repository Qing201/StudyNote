- [Planning](#planning)
  - [Path Planning](#path-planning)
    - [Dijkstra](#dijkstra)
    - [A\*](#a)
    - [D\*](#d)
    - [](#)

# Planning
路径规划（Path/Motion Planning），是在不考虑临时或者移动的障碍物的前提下，对车辆在空间上的变化的规划；

轨迹规划（Trjectory Planning）一般轨迹规划包括横向规划和纵向规划，横向规划主要输出trajectory中的x, y, s，纵向规划主要填充轨迹上各点期望速度ds/dt。一般横纵解耦规划方案先规划横向，再规划纵向。

## Path Planning

### Dijkstra
[How Dijkstra's Algorithm Works (YouTube)](https://www.youtube.com/watch?v=EFg3u_E6eHU)
```
for each vertex v:
    dist [v] = ∞
    prev[v] = none
dist [source] = 0
set all vertices to unexplored 
while destination not explored:
    v = least-valued unexplored vertex
    set v to explored for each edge (v, W):
    if dist[v] + len(v, w) < dist [w]:
        dist[w] = dist[v] + len(v, w)
        prev[w] = v
```

### A*
[The hidden beauty of the A* algorithm (YouTube)](https://www.youtube.com/watch?v=A60q6dcoCjw)

A* 在 Dijkstra 的基础上，将每个点到终点的距离作为heuristic加入到weight中。这样可以使 Dijkstra 算法更趋近于朝向终点的路径规划
1. Choose clever heuristic (potentials).
2. Apply potential reweighting.
3. Run Dijkstra on the new graph.

Good heuristic satisfies:
1. heuristic(start) as high as possible
2. For every edge (u,v) :
heuristic(u) < heuristic(v) + length(u,v)
Implies that for every node u:
    heuristic(u) < distance(u, end)
3. We can compute it fast.
   
### D*

### 