- [Week 1:](#week-1)
  - [Class 2](#class-2)
  - [Class 3](#class-3)
- [Week 2](#week-2)
  - [Class 1](#class-1)
- [Graphs](#graphs)
  - [Class 2](#class-2-1)

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

<br>

```diff
+ Week 2 Class 1
```

# Graphs

Undirected Graph:

Directed Graph:

Sparse graphs: $m ≪ n^2$

<br>

```diff
+ Week 2 Class 2
```
### Breadth-First Search(BFS) 
level by level search

runtime: 
* $O(n^2)$ in genal. ![Runtime Analysis](Image/BFS_Analysis.png)
* $(n+m) if sparse graphs
Application: Shortest Paths

#### Bipartite Graph
> odd cycle is, 

### Depth-First Search (DFS) 
go one deep frist and go back 

#### Articulation Points

Leaf nodes(Leaves): The botten nodes in every way of the tree. Node without children
Internal nodes: Node have at least one child
Root: Node without parent

```diff
+ Class 4.1
```

# Greedy Algorithm
