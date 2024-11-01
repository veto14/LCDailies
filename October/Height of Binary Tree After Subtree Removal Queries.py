class Solution:
    def calculateDepthAndHeight(self, node: Optional[TreeNode], depth: int, heights: Dict[int, int], depths: Dict[int, int]) -> int:
        if not node:
            return -1
        depths[node.val] = depth
        left_height = self.calculateDepthAndHeight(node.left, depth + 1, heights, depths)
        right_height = self.calculateDepthAndHeight(node.right, depth + 1, heights, depths)
        heights[node.val] = max(left_height, right_height) + 1
        return heights[node.val]

    def treeQueries(self, root: TreeNode, queries: List[int]) -> List[int]:
        heights = {}
        depths = {}
        
        # Calculate depth and height for each node
        self.calculateDepthAndHeight(root, 0, heights, depths)

        # Calculate max heights at each depth level excluding specific subtrees
        max_heights = {}
        for node, depth in depths.items():
            max_heights.setdefault(depth, []).append(heights[node])
        
        # Precompute maximum height per depth level excluding each node
        max_height_excluding = {}
        for depth, h_list in max_heights.items():
            h_list.sort(reverse=True)
            if len(h_list) == 1:
                max_height_excluding[depth] = {h_list[0]: -1}
            else:
                max_height_excluding[depth] = {h_list[0]: h_list[1]}
                for i in range(1, len(h_list)):
                    max_height_excluding[depth][h_list[i]] = h_list[0]

        results = []
        for query in queries:
            q_depth = depths[query]
            q_height = heights[query]
            if max_height_excluding[q_depth][q_height] == -1:
                remaining_height = q_depth - 1  # height excluding this entire level
            else:
                remaining_height = q_depth + max_height_excluding[q_depth][q_height]
            results.append(remaining_height)
        
        return results