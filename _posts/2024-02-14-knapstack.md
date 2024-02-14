---
title: 0/1 Knapsack Problem
published: true
share-description: ""
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/0-1-Knapsack-problem"
share-description: "0/1 Knapsack problem and its variations"
comments: false
---

We are given N items where each item has some weight (wi) and value (vi) associated with it.
We are also given a bag with capacity W. The target is to put the items into the bag such that
the sum of values associated with them is the maximum possible.Note that here we can either put an item completely into
the bag or cannot put it at all.

First Approach:

Ideally this is a enhanced recursion or so called dynamic programming problem.
Consider the universe of all possible subsets of items.We need to find the subset having the maximum value.
There are 2 ways in which we can start reducing our universe,we can reduce our universe to exclude subsets
which cannot be part of the result or we can iterate over the result and find the subset having the
maximum value.We use a combination of both ways.

> Inputs:

> profit[ ] = { 160, 1000, 120 };

> int weight[ ] = { 10, 20, 30 };

The above 2 arrays have the profit and weight of each item.

> W =50 W is the weight of the knapstack.

> int n =3 n number of items

Basically we try to reduce our universe.
We start from the end of the vector profit.Whether we start from end or from start or from any order
is not important.What is important is that we pick each item only one.
Every item can either be in our result set or it cannot be.

Case 1) Item at position 3 is in our result set.In that can we can reduce our knapstack problem
to 2 items.So our final result is profit of last item plus knapstack result of n-1 items.
This time when we reduce our knapstack problem we reduce both n and the pending weight of the knapstack
since we have already included this item.

Case 2) Item at position 3 is not in our result set.
So we can reduce our knapstack problem to size 2.
This time when we reduce our knapstack problem we reduce only n since we have not included this item.

Case 3) Size of last item is more that the maximum weight knapstack can hold.
We just leave this case since we know that this item cannot be part of final result.
But even in this case we need to run the knapstack over the reaming n-1 items.
This time when we reduce our knapstack problem we reduce only n since we have not included this item.

Let us start with 2 simple c++ files the driver code and our recursive code:

```c++
// Driver Code
using namespace std;
int main()
{
int profit[] = {
60, 100, 120
};
int weight[] = { 10, 20, 30 };
int W = 50;
int n = 3;
cout << knapSack(W, weight, profit, n);
return 0;
} 
```

```c++
// Recursive  Function
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
// to be done
return 0;
} 
```

Now in every call we reduce n (the last paramter.).Since we are using this to iterate over the vector
so techically we reduce our universe.If there is nothing left n is 0 .Where does this 0 go it goes in the calculation of max up in the call
stack.Since our function has to return int even if n==0 so we return 0.
It is possible that 0 is the result .. i.e the edge case when all items
are of size greater than the knapstack.

If the size of last item in more than the size of the knapstack we just ignore that item and the problem gets reduced to n-1 items.

So at this point we are here.
It is important to note that the paramter n is the nth item of the vector.
But nth item of the  vector has index n-1 ..So we use wt[n-1] > W


```cpp
// Recursive  Function
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
if (n ==0){
return 0;
}
if (wt[n-1] > W){
// item having index n-1 is not included
return knapSack( W, wt, val, n-1);
}


return max(val[n-1]+knapSack( W-val[n-1], wt, val, n-1)// item having index n-1 is  included

, knapSack( W, wt, val, n-1)) // item having index n-1 is not included


// to be done
} 
```

