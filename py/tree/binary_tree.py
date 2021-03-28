from typing import List


class TreeNode:
    def __init__(self, val: int = 0, left = None, right = None) -> None:
        self.val = val
        self.left = left
        self.right = right

class Solution:
    """
    递归模板:
    def order_recursion(self, root: TreeNode = None) -> List[int]:
        res = []
        def dfs(root):
            if not root: return

            res.append(root.val) # Position 1
            dfs(root.left)       # Position 2
            dfs(root.right)      # Position 3
        
        dfs(root)

        return res
    
    preorder_recursion: P1 -> P2 -> P3
    inorder_recursion : P2 -> P1 -> P3
    postorder_recursion: P2 -> P3 -> P2

    ======================================================================

    迭代模板:
    """
    def preorder_traversal_recursion(self, root: TreeNode = None) -> List[int]:
        res = []
        def dfs(root):
            if not root: return

            res.append(root.val)
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        return res

    def preorder_traversal_iteration(self, root: TreeNode = None) -> List[int]:
        if not root: return []

        stack, res = [root], []
        while stack:
            node = stack.pop()
            if node:
                res.append(node.val)
                if node.right:
                    stack.append(node.right)
                if node.left:
                    stack.append(node.left)
        return res

    def inorder_traversal_recursion(self, root: TreeNode = None) -> List[int]:
        res = []
        def dfs(root):
            if not root: return
            dfs(root.left)
            res.append(root.val)
            dfs(root.right)
    
        dfs(root)
        return res

    def inorder_traversal_iteration(self, root: TreeNode = None) -> List[int]:
        if not root: return []

        stack, res = [root], []
        while stack:
            node = stack.pop()
            if node:
                if node.right:
                    res.append(node.right)
                res.append(node.val)
                if node.left:
                    res.append(node.right)

        return res
    