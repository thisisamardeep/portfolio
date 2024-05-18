---
title: Empty base optimization  C++
published: true
tags: [ c++ ]
readtime: true
permalink: "/empty-base-class-optimization"
share-description: "Empty base optimization in  C++"
comments: false
---

First Let me share the cpp reference [EBO](https://en.cppreference.com/w/cpp/language/ebo) .

a important role in ensuring that our ours are what they are supposed to be.

By design c++ does not have invariant keyword but almost always when we write

libraries we need to ensure that after we construct a object it holds 

certian conditions.It can also hold after a function which may or may not 

change the object has finished or after a move constructor.There are also cases

where we dont want to call our invariants like suppose we have a private 

member function which can change the interface in a way in which other 

public members cannot.

Third approach First we just write a for loop which iterators over the array and

if nums [i] > nums [i + 1] it just swaps.

```cpp

class Solution {
public:
    void sortColors(vector<int> &nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            } else {

            }
        }

    }
};

```

Now we need to create 2 pointers.. the rightest index where 0 was see and the

righttest index where 1 was seen.

