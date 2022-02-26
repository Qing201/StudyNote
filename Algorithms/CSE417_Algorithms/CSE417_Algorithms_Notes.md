- [Graphs](#graphs)
    - [Breadth-First Search(BFS)](#breadth-first-searchbfs)
      - [Bipartite Graph](#bipartite-graph)
    - [Depth-First Search (DFS)](#depth-first-search-dfs)
      - [Articulation Points](#articulation-points)
  - [Node](#node)
- [Greedy Algorithm](#greedy-algorithm)
  - [Huffman Algorithm](#huffman-algorithm)
- [Divide and conquer](#divide-and-conquer)
  - [Merge sort](#merge-sort)
  - [Closest pair algorithm](#closest-pair-algorithm)
  - [Recurrence](#recurrence)
    - [Karatsuba multiplication](#karatsuba-multiplication)
    - [Master Recurrence](#master-recurrence)
- [Dynamic Programmin](#dynamic-programmin)
  - [Intro](#intro)
  - [Schedule](#schedule)
    - [Weighted Interval Scheduling](#weighted-interval-scheduling)
    - [Knapsack Algorithm](#knapsack-algorithm)
  - [](#)

> Week 1 Class 2

## Runtime

**Upper Bounds**:
$f(n)$ is $ O (g(n))$ if there is a constant $c > 0$ so that $f(n)$ is eventually always  $ \le c g(n) $

**Lower Bounds**:
$f(n)$ is $\Omega (g(n))$ if there is a constant $c > 0$ so that $f(n)$ is eventually always  $ \ge c g(n) $

**Both:**
$f(n)$ is $\Theta (g(n))$ if there is are constants $c1, c2 > 0$ so that eventually always $c_1g(n) \le f(n) \le c_2g(n)$

> Week 1 Class 3

**Logarithms**
Change-of=base formula:
$$ log_a(x) = \frac{log_b(x)}{log_b(a)}$$
$$ log_b(a) * log_a(x) = log_b(x)$$

For all $x>0$, *(no mater how small)* $log \ n =O(n^x)$

</br>

```diff
+ Week 2 Class 1
```

# Graphs

Undirected Graph:

Directed Graph:

Sparse graphs: $m ≪ n^2$

</br>

```diff
+ Week 2 Class 2
```

### Breadth-First Search(BFS)

level by level search

runtime:

- $O(n^2)$ in genal. ![Runtime Analysis](Image/BFS_Analysis.png)
- $(n+m) if sparse graphs
Application: Shortest Paths

#### Bipartite Graph

> odd cycle is,

### Depth-First Search (DFS)

go one deep frist and go back

#### Articulation Points

![arti_pint](Image/Articulation_Point.png)

## Node

- Leaf nodes(Leaves): The botten nodes in every way of the tree. Node without children
- Internal nodes: Node have at least one child
- Root: Node without parent

```diff
+ Class 4.1
```

# Greedy Algorithm

```diff
+ Class 4.3
```

## Huffman Algorithm

use the less bits to represent the every elements (the data has probobility)

```diff
+ Class 5.2
```

# Divide and conquer

The basic idea is divide one full size probelem to two half 
## Merge sort

sort the array

## Closest pair algorithm

![closest_pair](Image/Closest-Pair.png)

```diff
+ Class 5.3
```

![comparisions_closest_pair](Image/comparisons_of_closest_pair.png)
$C(n)$ is number of comparisons

## Recurrence

Merge sort

```diff
+ Class 6.1 2/7
```

### Karatsuba multiplication

![Karatsuba_multiplication](Image/Karatsuba_multiplication.png)

$$\sum ^k_{i=0} x^i = \frac{x^{k+1}-1}{x-1}$$

```diff
+ Class 6.2 2/9
```

### Master Recurrence
![Master_recurrence](Image/Master_Recurrence.png)

```diff 
+ Class 6.3 2/11
```

# Dynamic Programmin

## Intro
```diff 
+ Class 7.1 2/14
```
Eg. Give the elements 1, 4, 5, Find the min number of element to get 27.
5|4|1|total </br> number
-|-|-|-
5|0|2|7
4|1|3|8
3|3|0|6
![](Image/dp_eg1.1.png)
OPT($i$) is the min number of stamps totaling $i$

![](Image/dp_eg1.2.png)
Run time: $O(n)$
In this way, we do not know which number is the elements, but we can use trace back

**Trace-Back**
![](Image/dp_eg1.3.png)

## Schedule

### Weighted Interval Scheduling
Jobs with start time, end time, and value. Time may be confilict, find most valueable sequency.
![](Image/Weight_Schedule.png)
![](Image/Weight_Schedule_table.png)
The job is sorted by the end time. $p_j$ is last possible job. $v_j$ is the value.

```diff 
+ Class 7.2 2/16
```

That can only find the optimal value, so we need use traceback to find the solution which job has been counted.
![](Image/Weight_Schedule_traceback.png)
![](Image/Weight_Schedule_traceback_table.png)

### Knapsack Algorithm
![](Image/Knapsack_Algorithm.png)

Last number in line 5: 40 = max(40, 28+7)
Red line: 24 = max(6+18, 7) =24 &emsp; *where 6: 2{1,2} &emsp; 18: $v_3$

## 