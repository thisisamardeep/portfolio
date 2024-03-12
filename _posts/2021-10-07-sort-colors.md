---
title: Sort Colors
published: true
tags: [ leetcode ]
readtime: true
permalink: "/sort-colors"
share-description: "Sort Colors"
comments: false
---

We will solve all the below 3 problems using the similar  logic .

[Sort Colors](https://leetcode.com/problems/sort-colors/description/) 

[Sort List](https://leetcode.com/problems/sort-list/description/) 

[Wiggle Sort](https://leetcode.com/problems/wiggle-sort-ii/description/) 



First let us start with sort colors problem and do the brute force method.

We have a array of vectors having 0,1,2.We need to sort this.

We make 3 new arrays and loop over the existing array and keep pushing elements as needed.

At the end we have 3 arrays so we need to merge ( in cpp language insert elements).

So we take the first and second array at the last of first array we insert the second array.

Now at the last of first array we insert the third array.
