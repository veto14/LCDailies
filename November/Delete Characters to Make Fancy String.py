class Solution:
    def makeFancyString(self, s: str) -> str:
        result = []
        
        for char in s:
            if len(result) < 2 or not (result[-1] == result[-2] == char):
                result.append(char)
        
        return ''.join(result)
