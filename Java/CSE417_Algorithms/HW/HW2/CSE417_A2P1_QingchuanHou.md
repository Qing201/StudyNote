#### CSE 417: Homework 2
<br/>

#### Name: Qingchuan Hou
#### Student ID: 2127437
#### UWNetID: qhou
<br/>

Problem 1:
(FYI, this is the corrected version of the problem I botched last week. Your partial progress on it last week may be relevant, but please re-read it carefully to be sure you aren’t carrying forward misconceptions. The old version is included, if it is helpful for you to understand what changed, but I recommend, if possible, that you ignore it, and approach with fresh eyes.)
The Team USA Winter Olympic 5-Person Snowball Throwing Trials are approaching. There are n coaches available; each will coach one 5-Person Snowball Throwing Team (“5PSTT” for short). 5n athletes are eagerly competing for these highly coveted 5PSTT slots. After practices, trials and training, each athlete ranks the n coaches, and each coach ranks all 5n athletes.
This is the old, faulty text. Ignore it if possible: A “stable team assignment” assigns 5 athletes to each coach so that no coach c is assigned and athlete a who would prefer a different coach c′ and simultaneously c′ is assigned an athlete a′ who prefers coach c.
New Text: A “team assignment” partitions the athletes into n groups of 5 and matches each group to a coach. Such an assignment is “stable” if it contains no “instabilities.” An instability in such an assignment is a pair of athletes a1 and a2 and a pair of coaches c1 and c2 such that ai is on ci ’s team (i = 1, 2), but coach c1 would prefer to have a2 and a2 would rather be on c1’s team.
This is similar, but not identical, to the Stable Matching Problem (SMP) in the text. Explain how you could use, without modification, a subroutine that solves SMP to solve the Stable 5PSTT Problem (S5PSTTP). I.e., explain how to transform an S5PSTTP instance x into an SMP instance f(x) in such a way that any stable solution to the SMP instance f(x) can be easily converted into a stable solution to the S5PSTTP instance x. I’m looking for about 3 clear, English language, paragraphs explaining (1) how to convert x to f(x) (2) how to recover a solution to the S5PSTTP instance x from a Stable Matching found in f(x), and (3) explaining why that result is actually a “stable team assignment”. I expect that your solution would require O(n2) time (which is linear in the size of the data that describes a problem instance, namely a pair of 5n × n preference matrices), excluding the time taken by the SMP subroutine; briefly justify this (if true), or explain why your method may be slower.

