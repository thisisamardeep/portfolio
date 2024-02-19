---
title: Possible ways to find permutations
published: true
share-description: ""
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/permutation-possible-ways"
share-description: "Different Possible ways to find permutations using backtracking"
comments: false
---

Problem:
We have array of 3 numbers [1,2,3].We need to find list of all possible permutations using backtracking.
Backtracking is just enhanced recursion (may or may not be memoized).


![strace](/portfolio/img/diagram.jpg)

In the above diagram .We start with 2 arrays on this the array which we have one is the new array which will be part of the final
solution.Think of the right array in terms of fixing the element.So first we try to fix the element at position 1.
We take the first element from the left array and fix it at position 1.Now there are other elements also which can be fixed at position 1.
How do we make sure that they get covered.So we swap the first element with second.Then we swap the first element with third and so one.
Also note that in our code we would also need to swap second element with first after we are done with that case since we want the vector to come
back to its original state.
I will come to that later.
