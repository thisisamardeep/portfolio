---
title: Polymorphic Dispatching
published: true
tags: [ leetcode ]
readtime: true
permalink: "/polymorphic-dispatch"
share-description: "Polymorphic Dispatching"
comments: false
---

We will explain Polymorphic dispatching using Templates.

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

