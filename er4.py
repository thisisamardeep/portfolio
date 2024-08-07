# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def find_bst_amar(self, root: Optional[TreeNode]) -> bool:
        my_stack = []
        prev = None
        curr = root
        while curr is not None or len(my_stack) != 0:
            while curr is not None:
                my_stack.append(curr)
                curr = curr.left
            curr = my_stack[-1]
            if prev is None:
                prev = curr
            else:
                if curr.val < prev.val:
                    return False
                prev = curr
            my_stack.pop()
            curr = curr.right
        return True

    def find_sum_amar(self, root: Optional[TreeNode]) -> int:
        my_stack = []
        prev = None
        curr = root
        res = 0
        while curr is not None or len(my_stack) != 0:
            while curr is not None:
                my_stack.append(curr)
                curr = curr.left
            curr = my_stack[-1]
            res = res + curr.val
            my_stack.pop()
            curr = curr.right
        return res

    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        my_queue = []
        res_final = 0
        my_queue.insert(0, root)
        while len(my_queue) != 0:
            len_queue = len(my_queue)
            for i in range(0, len_queue, 1):
                front = my_queue[-1]
                my_queue.pop()
                if self.find_bst_amar(front) is True:
                    temp = self.find_sum_amar(front)
                    res_final = max(res_final, temp)
                if front.left is not None:
                    my_queue.insert(0, front.left)
                if front.right is not None:
                    my_queue.insert(0, front.right)
        return res_final


Sdd = Solution()

t4 = TreeNode(4)
t3 = TreeNode(3)
t2 = TreeNode(2)
t1 = TreeNode(1)

t4.left = t3
t3.left = t1
t3.right = t2

errr = Sdd.maxSumBST(t4)
print(errr)
