---
title: Find the next permutation
published: false
share-description: ""
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/permutation-next"
share-description: "Find the next lexicographic permutation"
comments: false
---

[Problem Link](https://leetcode.com/problems/next-permutation/description/)

We have array of 4 numbers [1,2,3,4].We need to find the next permutation. By next permutation we mean the next
lexicographic permutation.

First let us leave the problem and try to find the solution for another problem
Suppose you have a number 1234.You need to find the smallest next number you can form using these digits only once.
Just note the largest number we can form is 4321.

So along the path 1234 --> 4321 some others numbers are also present .We need to find the first number in that path.

One thing is clear the next number will be larger than 1234.So it means we need to swap exactly 2 digits of 1234(leaving
a edge case)
such that the smaller digits goes to right and greater digit comes to left,then only we get to the next number.

Let us start from right end of 1234.We find the first index i such that digit at i is less than digit at i+1.
In this case i=2 since 3 < 4.

So we split our array into 2 parts 123 4.
let us mark index of 3 with idx=2.
Now again we start from right and find the first number which is greater than 3 and then swap it with 3.
Here that number is 4. So we swap 3 and 4.We reverse the digits of the second array here it is only 4 so it does not
matter. We get 1243.

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
The we again start from right and find righidx such that nums[idx] < nums[j].

```cpp
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int idx = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            // edge case
            reverse(nums.begin(), nums.end());
            return;

        } else {
            // need to handle the normal case
            int rightidx = -1;
            //Now we start from right and find rightidx such that number at idx is less than number at rightidx
            for (int j = nums.size() - 1; j > idx; j--) {
                if (nums[idx] < nums[j]) {
                    rightidx = j;
                    break;
                }
            }
            if (rightidx == -1) {
                // this will never be the case
            } else {
                swap(nums[idx], nums[rightidx]);
                reverse(nums.begin() + idx + 1, nums.end());
                return;
            }
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

This the the final solution.This is good example of the power of multiple pointers or indexes.
The below is the same solution but in python since python objects are passed by reference and work different so some things are different.



```python
from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
      #  We need to modify nums in place
        if len(nums) == 0:
            return None
        if len(nums) == 1:
            return None
        swalpleft = -1  #left index to be swapped
        swalright = -1  #right index to be swapped
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                swalpleft = i
                break
        if swalpleft == -1:
            nums.reverse() # we need to use reverse() here since it modifies in place and returns none .Cannot use nums[::-1] here 
            return
        else:
            for j in range(len(nums) - 1, swalpleft, -1):
                if nums[j] > nums[swalpleft]:
                    swalright = j
                    break

            if swalright == -1:
                pass
                #this case never comes
            else:
                left = nums[swalpleft]
                right = nums[swalright]
                nums[swalpleft] = right
                nums[swalright] = left
            nums[swalpleft + 1::1] = nums[swalpleft + 1::1][::-1]
            # we play trick here nums[swalpleft + 1::1] creates a new list.Then we reverse it using [::-1] and again create a copy
            # but we need to modify  nums in place so we assign it back to  nums[swalpleft + 1::1] 
            return

test = Solution()
inp = [1, 3, 2]
test.nextPermutation(inp)
 
# (result is [2,1,3])
```
