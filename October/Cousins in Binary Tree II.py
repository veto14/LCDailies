class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def calculateDepthSums(node: Optional[TreeNode], level: int):
            if node is None:
                return
            if len(levelSums) <= level:
                levelSums.append(0)
            levelSums[level] += node.val
            calculateDepthSums(node.left, level + 1)
            calculateDepthSums(node.right, level + 1)

        def updateCousins(node: Optional[TreeNode], level: int):
            siblingsSum = (node.left.val if node.left else 0) + (
                node.right.val if node.right else 0
            )
            level += 1
            if node.left:
                node.left.val = levelSums[level] - siblingsSum
                updateCousins(node.left, level)
            if node.right:
                node.right.val = levelSums[level] - siblingsSum
                updateCousins(node.right, level)

        levelSums = []
        calculateDepthSums(root, 0)
        root.val = 0
        updateCousins(root, 0)
        return root