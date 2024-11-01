from typing import List
import bisect

class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        
        # Step 1: Compute LIS for each index
        inc = [0] * n
        lis = []
        for i in range(n):
            pos = bisect.bisect_left(lis, nums[i])
            if pos < len(lis):
                lis[pos] = nums[i]
            else:
                lis.append(nums[i])
            inc[i] = pos + 1
        
        # Step 2: Compute LDS for each index by reversing the array
        dec = [0] * n
        lds = []
        for i in range(n - 1, -1, -1):
            pos = bisect.bisect_left(lds, nums[i])
            if pos < len(lds):
                lds[pos] = nums[i]
            else:
                lds.append(nums[i])
            dec[i] = pos + 1
        
        # Step 3: Calculate the maximum mountain length
        max_mountain_length = 0
        for i in range(1, n - 1):
            if inc[i] > 1 and dec[i] > 1:  # valid peak
                max_mountain_length = max(max_mountain_length, inc[i] + dec[i] - 1)
        
        # Step 4: Calculate minimum removals
        return n - max_mountain_length if max_mountain_length > 0 else n - 1
