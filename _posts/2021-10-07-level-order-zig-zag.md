---
title: Binary Tree Zigzag Level Order Traversal
published: true
tags: [ leetcode ]
readtime: true
permalink: "/binary-level-zig-zag"
share-description: Binary Tree Zigzag Level Order Traversal
comments: false
---
We need to solve this  [Zig Zag](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)

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

python solution 


```python

from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        my_dict = {}
        maj_element = 0
        maj_element_count = 0

        for i in range(0, len(nums), 1):
            if nums[i] in my_dict:

                my_dict[nums[i]] = my_dict[nums[i]] + 1
                if maj_element_count < my_dict[nums[i]]:
                    maj_element_count = my_dict[nums[i]]
                    maj_element = nums[i]
            else:
                my_dict[nums[i]] = 1

        return maj_element



```


java solution


```java

class Solution {
    public int majorityElement(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        int resElement = 0;
        int resElementCount = 0;
        HashMap<Integer, Integer> temp = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (temp.containsKey(nums[i])) {
                Integer currval = temp.get(nums[i]);
                temp.put(nums[i], currval + 1);
                if (resElementCount < temp.get(nums[i])) {
                    resElement = nums[i];
                    resElementCount = temp.get(nums[i]);
                }
            } else {
                temp.put(nums[i], 1);
            }
        }
        return resElement;
    }

    ;
}


```