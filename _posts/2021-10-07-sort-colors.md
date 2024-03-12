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


```cpp
class Solution {
public:
    void sortColors(vector<int> &nums) {
        vector<int> zero{};
        vector<int> one{};
        vector<int> two{};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero.push_back(0);
            } else if (nums[i] == 1) {
                one.push_back(1);
            } else if (nums[i] == 2) {
                two.push_back(2);
            }
        }
        zero.insert(zero.end(), one.begin(), one.end());
        zero.insert(zero.end(), two.begin(), two.end());
        nums = zero;
    }
};

```


Second Approach .

Here we make sure that we dont create new arrays so first we do one pass and count

the counts of each type.Then we do another pass and just fill the array.

This removes the need for new array but it needs 2 passes.

```cpp
class Solution {
public:
    void sortColors(vector<int> &nums) {
        int count_zeros = 0;
        int count_ones = 0;
        int count_twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count_zeros = count_zeros + 1;
            } else if (nums[i] == 1) {
                count_ones = count_ones + 1;
            } else if (nums[i] == 2) {
                count_twos = count_twos + 1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < count_zeros) {
                nums[i] = 0;
            } else if (i >= count_zeros && i < count_ones + count_zeros) {
                nums[i] = 1;
            } else if (i >= count_ones && i < nums.size()) {
                nums[i] = 2;
            }
        }

    }
};

```

