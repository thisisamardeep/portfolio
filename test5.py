from typing import List


def mergme(inp, start, middle, end):
    res = []
    first = inp[start: middle + 1: 1]
    second = inp[middle + 1:end + 1: 1]
    print(first)
    print(second)
    print(33333333333333)

    i = 0
    j = 0

    while i < len(first) or j < len(second):
        print(i)
        print(j)
        if i < len(first) and j < len(second):
            if first[i] <= second[j]:
                res.append(first[i])
                i = i + 1
            else:
                res.append(second[j])
                j = j + 1
        elif i < len(first) and j >= len(second):
            res.append(first[i])
            i = i + 1
        elif i >= len(first) and j < len(second):
            res.append(second[j])
            j = j + 1
    return res


def amar(inp, start, end) -> None:
    if start == end:
        return
    middle = (start + end) // 2
    amar(inp, start, middle)
    amar(inp, middle + 1, end)
    inp[start:end + 1:1] = mergme(inp, start, middle, end)


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        amar(nums, 0, len(nums) - 1)
        return nums
