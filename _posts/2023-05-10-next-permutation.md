---
title: Find the next permutation
published: true
share-description: ""
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/permutation-next"
share-description: "Find the next lexicographic permutation"
comments: false
---

Problem Link:[https://leetcode.com/problems/next-permutation/description/]

We have array of 4 numbers [1,2,3,4].We need to find the next permutation. By next permutation we mean the next
lexicographic permutation.

First let us leave the problem and try to find the solution for another problem
Suppose you have a number 1234.You need to find the smallest next number you can form using these digits only once.
Just note the largest number we can form is 4321.

So along the path 1234 --> 4321 some others numbers are also present .We need to find the first number in that path.

One thing is clear the next number will be larger than 1234.So it means we need to swap exactly 2 digits of 1234(leaving a edge case)
such that the smaller digits goes to right and greater digit comes to left,then only we get to the next number.

Let us start from right end of 1234.We find the first index i such that digit at i is less than digit at i+1.
In this case i=2 since 3 < 4.

So we split our array into 2 parts 123 4.
let us mark index of 3 with idx=2.
Now again we start from right and find the first number which is greater than 3 and then swap it with 3.
Here that number is 4. So we swap 3 and 4.We reverse the digits of the second array here it is only 4 so it does not matter. We get 1243.

So next permutation of 1234 is 1243.

Now again we start to find the next permutation.

Let us start from right end of 1243.We find the first index i such that digit at i is less than digit at i+1.
here it is 1 and digit is 2 .So we split our array 12 43.
let us mark index of 2 with idx=1.

Now again we start from right and find the first number which is greater than 2 and then swap it with 2.
3 is greater than 2. So we swap 2 and 3 .We get 13 42 but note it does not end here.We need to reverse the second array.
So we get 1324 and so on.

The exact same concept can be applied to this problem using number of strings or anything which has a order.

Now let us leave thoery and start coding.
We have the starter code below.We have used reference so we just alter the input vector which we get.
```cpp
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int idx=-1;
        for(int i=nums.size();i >=0;i++){
            
        }
        
       // Need to implement this
    }
};


int main() {
    vector<int> input = {1, 2, 3, 4};
    Solution s{};
    s.nextPermutation(input);
    return 0;
}
```

We start from right and find the index idx such that input[idx] < input[idx+1].
If we dont find anything we mark it as -1 and just reverse the digits(edge case.)

```cpp


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
void nextPermutation(vector<int> &nums) {
int idx = -1;
for (int i = nums.size() - 2; i >= 0; i++) {
if (nums[i] < nums[i + 1]) {
idx = i;
break;
}
}

if (idx == -1) {
// edge case
reverse(nums.begin(),nums.end());
return;

} else {
// need to handle the normal case
}
}
};

int main() {
vector<int> input = {1, 2, 3, 4};
Solution s{};
s.nextPermutation(input);
return 0;
}



```