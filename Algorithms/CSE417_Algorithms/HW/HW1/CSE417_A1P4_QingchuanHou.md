#### CSE 417: Homework 1 
<br/>

#### Name: Qingchuan Hou
#### Student ID: 2127437
#### UWNetID: qhou
<br/>

Problem 4:
Assuming that your computer can perform 10 billion operations per second, what is the largest value of n such that you can complete the following number of operation in one hour?

$$
\begin{align*}
  & 10 \ \text{billion operation/seconde} \\
= & 10^{10} \times 60 \times 60 \\
= & 3.6 \times 10^{13} \ \text{operation/hour}
\end{align*}
$$

In this question, $ n \in \N$.

a) $ n^2 \le 3.6 \times 10^{13} \ \rightarrow \ n_{Max} = 6 \times 10^6$

b) $ n^3 \le 3.6 \times 10^{13} \ \rightarrow \ n_{Max} = 3.3019 \times 10^4$

c) $ 100 n^2 \le 3.6 \times 10^{13} \ \rightarrow \ n_{Max} = 6 \times 10^5$

d) $ nlog_2n \le 3.6 \times 10^{13} \ \rightarrow \ n_{Max} = 9.063 \times 10^{11}$

e) $ 2^n \le 3.6 \times 10^{13} \ \rightarrow \ n_{Max} = 45 $

f) $ 2^{2^n} \le 3.6 \times 10^{13} \ \rightarrow \ n_{Max} = 5 $
