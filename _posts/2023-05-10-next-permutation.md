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

Suppose you have a number 6579 and you need to find the smallest number larger than this number which can
be formed from the digits 6,5,7,9 using the digits only once.
How will you find ? or better how will the cpu be able to find it.
Ome thing is clear since we need to find a number larger than 

![strace](/portfolio/img/diagram.jpg)

In the above diagram .We start with 2 arrays .The right array is the new array which will be part of the final
solution.Think of the right array in terms of fixing the element.So first we try to fix the element at position 1.
We take the first element from the left array and fix it at position 1.Now there are other elements also which can be fixed at position 1.
How do we make sure that they get covered.So we swap the first element with second.Then we swap the first element with third and so one.
Also note that in our code we would also need to swap second element with first after we are done with that case since we want the vector to come
back to its original state.
I will come to that later.
Find the below driver code and the starter code of our function.

```cpp
#include "vector"
using namespace std;
void findpermutations() {
};

int main() {
    int input[] = {1, 2, 3};
    int n = 3;
    findpermutations(vector<int> &input,const int &n,int tempsize);
    return 0;
}
```


Now the main question is our function findpermutations will have what parameters?
This question is the most important in any dynamic programming problem. Once this is done almost 50% of the work is done.
We need to pass reference to our input array since we will be swapping and swap back the elements so it will not be const.
Also we need to pass the number of elements in our array. Also note temp  is  valid value after the function is called.I mean temp refers to the partial candidate we have
after the function call.Also we need to pass reference of finalresult .This will be our final result.
We need to pass temp by reference but why ? C++ is notorious for making copies of paramters.Also we can have only one partial candidate at one point of time.
So there are 2 ways either use a reference and add and delete to our partial candidate or work with copies which is very cumbersome.

Now if size_temp  == n then it means our partial candidate is a actual candidate


If you see the diagram above as we go down the level, the index of the element which we have fixed increases.We started with nothing so let us keep it as 0.
After first call we are at level 2 of the diagram.But note that we need to know the fixed index at level 1 since level 2 is just child of level 1.
Let us say it this way "for our program to go to level2 from level 1 i need to know the index at level 1 ".


Current state of our code.

```cpp
#include "vector"
using namespace std;

void findpermutations(vector<int> &input, size_t n, vector<int> &temp,
                      vector<vector<int>> &finalresult, int last_fixed_index) {
    if (temp.size() == n) {
        finalresult.push_back(temp);
        return;
    }
    // pending
};

int main() {
    vector<int> input{1, 2, 3};
    size_t n = 3;
    vector<int> temp{};
    vector<vector<int>> finalresult{};
    findpermutations(input, n, temp, finalresult, 0);
    return 0;
}
```

Now for last_fixed_index == 0 for the first call.There are 3 elements that can be fixed at this place 1 ,2,3.
So we start a loop from the fixed index iterate over the rest of array .The reason why we loop is since we  need to change the element
at first index 0.

Once we start the loop we swap the elements i and the element last_fixed_index. Why ?
Let me explain the logic here.We need to make sure that in position last_fixed_index we try to place all possible elements.
Where do we get the all possible elements  --> From the counter i of the loop.So our swap function takes 3 arguments swaps the elements ar position i and j thats it.
Now once we swap we know the we have got the element of the partial candidate ..so we push the element to temp and note we also need to remove this later.
Why ? Because in the next iteration temp will change so basically after we done will calling findpermutations we revert temo to its original state.

Final working code

```cpp
#include "vector"

using namespace std;

void swapme(vector<int> &swap_me, size_t i, size_t j) {
int t1 = swap_me[i];
swap_me[i] = swap_me[j];
swap_me[j] = t1;

}

void findpermutations(vector<int> &input, size_t n, vector<int> &temp,
vector<vector<int>> &finalresult, int last_fixed_index) {
if (temp.size() == n) {
finalresult.push_back(temp);
return;
}

    for (size_t i = last_fixed_index; i < n; i++) {
        swapme(input, last_fixed_index, i);
        temp.push_back(input[last_fixed_index]);
        findpermutations(input, n, temp, finalresult, last_fixed_index + 1);
        temp.pop_back();
        swapme(input, i, last_fixed_index);
    }


};

int main() {
vector<int> input{1, 2, 3};
size_t n = 3;
vector<int> temp{};
vector<vector<int>> finalresult{};
findpermutations(input, n, temp, finalresult, 0);
return 0;
}

```

The tough part in backtracking is not the code but understanding layers and layers beneath the code.Once you get used to it ,it becomes very easy.
Also note in this approach the order on the resultset is not in lexographic order.
Many times we need to find results in lxographic order in dynamic programming problems.In this case we cannot use this method.

Let us try to understand why this method does not produce results in lexographic order.Suppose we start with input ={3,2,1}.
Just to be clear the output of our program for this input is [[3,2,1] ,[3,1,2],[2,3,1],[2,1,3],[1,2,3],[1,3,2]]
Since we run loop from index our ,this ensures that all candidates starting from 3 appear before all candidates starting from 2 and so on.But this happens only at the first level.
See the sublevel 1 [1,2,3][1,3,2]  .Here {1,2,3} has appeared before {1,3,2}.See how did we get 1 in both these results we had swapped with 3.
But once 1 came after swapping with 3.

{3,2,1} had become {1,2,3}  (This case was the last case of the first loop). Then in th sub loops 2 swapped with itself and 3 swapped with itself and we got {1,2,3}
After than 2 swapped with 3 so we got {1,3,2}.So only at the first level we were able to maintain the order once we entered into subloops we were just swapping without maintaining the ordering.
That is the reason this method fails to generated lexographic permutations.
