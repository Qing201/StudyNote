#### CSE 417: Homework 4
##### Name: Qingchuan Hou
##### Student ID: 2127437
##### UWNetID: qhou
<br>

##### Problem 6:
<br>

<br>

(b)
average number of bits per character = $ \frac{2 \times 7 + 2 \times 6 + 3 \times 5 + 5 \times 4 + 8 \times 3 + 13 \times 2 + 21 \times 1}{54} \approx 2.44$

(c)
The character with smaller frequency has the longer Huffman code. If there are n characters, the character with the longest code has the n-1 number of Huffman code. $F_1$ and $F_2$ both have the same and smallest frequency. So the $F_1$ and $F_2$ both have the longest Huffman code. The $F_i$ with a bigger $i$ will have the bigger frequency, so the Huffman code will be shorter.

In the Huffman tree in question a, we can see the sum of first $n$ Fibonacci numbers will never be bigger than the $F_{n+2}$, so in the Huffman tree of Fibonacci numbers, it will always combine the subtree of first n numbers and $F_{n+1}$. So every level of tree will have a subtree of previous characters and a real character. *(except the deepest level which have $F_1$ and $F_2$)* So the depth of Huffman tree with n number of Fibonacci characters will be $n-1$, and the depth of every character will sort the number from big to small.

Take my Huffman tree in question (a) as a reference. If there are n characters, then we have:
The Huffman code for $F_1$: "n-1 number of 0"
The Huffman code for $F_2$: "( n-2 number of 0 ) + 1"
The Huffman code for $F_i$: "( n-$i$ number of 0 ) + 1" &emsp; &emsp; &emsp; &emsp;*(except $F_1$)*

