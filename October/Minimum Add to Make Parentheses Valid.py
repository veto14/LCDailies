class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open_count = 0        # Count of unmatched '('
        close_needed = 0      # Count of unmatched ')'

        for c in s:
            if c == '(':
                open_count += 1  # Track unmatched '('
            else:  # c == ')'
                if open_count > 0:
                    open_count -= 1  # Match ')' with an unmatched '('
                else:
                    close_needed += 1  # Unmatched ')'

        # Total insertions required = unmatched '(' + unmatched ')'
        return open_count + close_needed