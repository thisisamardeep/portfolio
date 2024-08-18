from typing import List
from typing import Optional
from recviz import recviz

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        # @recviz
        def dfs(root: TreeNode):
            if root is None:
                return [0, 0]
            leftPair = dfs(root.left)
            rightPair = dfs(root.right)
            withRoot = leftPair[1] + rightPair[1] + root.val
            withoutRoot = max(leftPair[0], leftPair[1]) + max(rightPair[0], rightPair[1])

            return [withRoot, withoutRoot]

        res = dfs(root)
        return max(res[0], res[1])


t31 = TreeNode(3)
t32 = TreeNode(3)
t33 = TreeNode(3)
t2 = TreeNode(2)
t1 = TreeNode(1)

t31.left = t2
t31.right = t33
t33.right = t1
t2.right = t32

dsddf = Solution()
rrrr4 = dsddf.rob(t31)
print(rrrr4)