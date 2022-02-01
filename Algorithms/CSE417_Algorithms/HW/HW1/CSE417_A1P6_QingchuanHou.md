#### CSE 417: Homework 1 
<br/>

#### Name: Qingchuan Hou
#### Student ID: 2127437
#### UWNetID: qhou
<br/>

Problem 6:
Suppose functions $f(n) > 0$ and $g(n) > 0$ satisfy $f(n) = O(g(n))$. Prove or give a counterexample to each ofthe following.

a) $ log_2f(n) = O(log_2g(n)) $

Because $f(n) = O(g(n))$, $f(n) \le cg(n)$ 
so, when $g(n) > 2$

$$ 
\begin{align*}
log_2f(n) & \le log_2cg(n) \\
log_2f(n) & \le log_2c + log_2g(n) \\
log_2f(n) & \le clog_2g(n) \qquad \text{for} \ c \ge 1
\end{align*}
$$

Therefore, $$ log_2f(n) = O(log_2g(n)) $$
<br>

b) $ 2^{f(n)} = O(2^{g(n)}) $
Because $f(n) = O(g(n))$, $f(n) \le cg(n)$
Assume $f(n) = n$ and $g(n) = 2n$
Then, $2^{f(n)} = 2^n$, $2^{g(n)} = 2^{2n} = 4^n$
for all $ n \ge 0 $, have $2^n \le 4^n$
so,
$$
\begin{align*}
2^{f(n)} & \le c2^{g(n)} \qquad for \ c \ge 1 \\ 
\end{align*}
$$

Therefore, $$ log_2f(n) = O(log_2g(n)) $$
<br>

c) $ {(f(n))^2} = O({(g(n))}^2) $

Because $f(n) = O(g(n))$, $f(n) \le cg(n)$ 
so, for $g(n) \ge 1$

$$ 
\begin{align*}
{(f(n))^2} & \le {(cg(n))}^2 \\
{(f(n))^2} & \le c^2{(g(n))}^2 \\
{(f(n))^2} & \le \dot c{(g(n))}^2 \qquad \text{where} \ \dot{c} = c^2, \text{and} \ c \ge 1\\
\end{align*}
$$

Therefore,
$$ {(f(n))^2} = O({(g(n))}^2) $$