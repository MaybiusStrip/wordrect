wordrect
========

C program to solve the word-rectangle problem.

The goal of the word rectangle problem is to find an n x m square where each column is a valid word and each row is a valid word. For example, consider this 5x5 word square:
```
S C E N T
C A N O E
A R S O N
R O U S E
F L E E T
```

For squares, the words can also be the same in both direction:

```
M O A N
O N C E
A C M E
N E E D
```

You can think of this problem as a search problem, where the solution space is all permutations of n x m two-dimensional arrays where each cell can be any letter in the alphabet. The goal is to find the n x m arrays where each column is a valid word and each row is a valid word. Thinking about it this way, we can easily visualize the brute force solution of trying every combination of every letter one by one.

The approach taken by this problem is to narrow down the search space one word at a time.

We start by picking a word for the first row:

```
S C E N T
* * * * *
* * * * *
* * * * *
```

Then we by picking a word for the first column, which we has to start with an S:

```
S C E N T
C * * * *
A * * * *
R * * * *
F * * * *
```

Now we want to pick a word for the second row, knowing that the first two letters in columns 2-5 have to be valid prefixes to words.

```
S C E N T
C A N O E
A * * * *
R * * * *
F * * * *
```

We then repeat this process. If we find ourselves in a situation where we cannot find a word such that the other incomplete words form valid prefixes -- so we have narrowed down the search space so that no valid solutions exist anymore -- we backtrack to the last word we picked and try another one. So say that in this situation, we could not find a word for column two, such that rows 3-5 were valid prefixes for words, we would try another word than CANOE for the second row and repeat the process.
