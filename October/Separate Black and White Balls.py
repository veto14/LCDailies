class Solution:
    def minimumSteps(self, s: str) -> int:
        count_black = 0
        min_steps = 0

        for char in s:
            if char == '1':
                count_black += 1
            elif char == '0':
                min_steps += count_black

        return min_steps
        