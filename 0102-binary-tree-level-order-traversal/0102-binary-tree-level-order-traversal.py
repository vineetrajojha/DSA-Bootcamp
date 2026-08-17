# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        queue = [root]
        ans = []
        if root == None:
            return ans

        while queue:
            arrlen = len(queue)
            level = []
            for i in range(arrlen):
                root = queue.pop(0)
                if root:
                    level.append(root.val)
                    queue.append(root.left)
                    queue.append(root.right)
            if level:
                ans.append(level)

        return ans