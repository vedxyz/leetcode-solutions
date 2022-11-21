# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class RecursiveSolution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        def inorder(node: Optional[TreeNode]):
            if not node: return
            inorder(node.left)
            result.append(node.val)
            inorder(node.right)
        inorder(root)
        return result

class IterativeSolution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result, stack = [], []
        node = root
        while node or stack:
            while node:
                stack.append(node)
                node = node.left
            
            node = stack.pop()
            result.append(node.val)
            node = node.right
        return result

