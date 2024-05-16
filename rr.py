from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:  # root is none(null)
            return 0
        q = [[root, 1]]  # start with root and depth 1

        mn = 10 ** 9
        while len(q) > 0:
            # x,d=q.pop(0)# for bfs
            x, d = q.pop(-1)  # for dfs
            c = 0
            if x.left:
                q.append([x.left, d + 1])
                c += 1
            if x.right:
                q.append([x.right, d + 1])
                c += 1
            if c == 0:  # if left and right children are none .leaf nodes
                mn = min(mn, d)  # at leaf compare distance from root.update minimum
        return mn
