from typing import List
import math

class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        # Sort robots and factories by positions
        robot.sort()
        factory.sort()

        # Number of robots and factories
        n, m = len(robot), len(factory)
        
        # Initialize dp array with infinity for minimization
        dp = [[math.inf] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = 0  # No distance for 0 robots and 0 factories

        # Fill dp table
        for j in range(1, m + 1):  # Iterate over factories
            dp[0][j] = 0  # Zero distance if no robots to repair
            
            # Iterate over robots
            for i in range(1, n + 1):
                dp[i][j] = dp[i][j - 1]  # Initialize by skipping the current factory

                # Track the total distance if we use factory `j-1` to repair robots
                total_dist = 0
                for k in range(1, min(factory[j - 1][1], i) + 1):
                    total_dist += abs(robot[i - k] - factory[j - 1][0])
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + total_dist)

        # Minimum distance to repair all robots using all factories
        return dp[n][m]
