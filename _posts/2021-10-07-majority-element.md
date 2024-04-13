---
title: Majority Element in a Array
published: false
tags: [ leetcode ]
readtime: true
permalink: "/majority-element"
share-description: Majority Element
comments: false
---
We need to solve this  [Majority Element](https://leetcode.com/problems/majority-element/description/)

c++ solution

```cpp
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int majElement = 0;
        int majElementCount = 0;
        map<int, int> mymap{};
        for (int i = 0; i < nums.size(); i++) {
            if (mymap.count(nums[i]) == 0) {
                mymap[nums[i]] = 1;
            } else {
                mymap[nums[i]] = mymap[nums[i]] + 1;
                if (majElementCount < mymap[nums[i]]) {
                    majElementCount = mymap[nums[i]];
                    majElement = nums[i];
                }
            }
        }
        return majElement;
    }
};
```
