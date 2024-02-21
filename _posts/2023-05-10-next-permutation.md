---
title: Find the next lexographic permutation
published: true
share-description: ""
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/next-lexographic-possible"
share-description: "Find the next lexographic permutation"
comments: false
---

Problem:
We have array of 3 numbers [1,2,3].We need to find list of all possible permutations using backtracking.
Backtracking is just enhanced recursion (may or may not be memoized).


First let us try to rephare and find solution to another problem.

Suppose you have a number 1234 and you need to find the smallest number larger than this number which can
be formed from the digits 1,2,3,4 using the digits only once.
How will you find ? or better how write psedu code to be able to find it.
Ome thing is clear since we need to find a number larger than this number so we need to swap 2 digits.
And the digits which we swap should be such that the digit to the left after swap should be greater than the digit to the right.

Now we need to understand another thing 2  cases are possible

Case 1)
 4->3 -> 2 ->1  (As we start from right to left the next digit is greater than or equal to the previous digit)

Case 2) All other cases.So there is always one index k such that element at index k is less than the element at index k+1.
      This is called the inflection point

New let us not try to find the next possible number after 1234 but focus on the largest possible number 4321.

                    [1234][]
    Start from right find the first element which is less than it right neighbour. it is 3 in this case. Since the array to right is empty move 4 to this array.
                    [12][43]
    Now again start from right from the last element 3,find the the index k such that element at index k is greater than element at index k+1.So we have found element 2 here.
    Now in the second subarray start from right and find the first number which is greater than 2. it is 3 in this case. So swap them
                    [13][42]
    
        Now swap 3 and 4
