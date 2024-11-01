from typing import List

class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        memo = {}

        def dfs(row: int, col: int) -> int:
            if (row, col) in memo:
                return memo[(row, col)]
            
            max_moves = 0
            for dr in [-1, 0, 1]:
                new_row, new_col = row + dr, col + 1
                if 0 <= new_row < m and new_col < n and grid[new_row][new_col] > grid[row][col]:
                    max_moves = max(max_moves, 1 + dfs(new_row, new_col))
            
            memo[(row, col)] = max_moves
            return max_moves

        max_result = 0
        for row in range(m):
            max_result = max(max_result, dfs(row, 0))
        
        return max_result