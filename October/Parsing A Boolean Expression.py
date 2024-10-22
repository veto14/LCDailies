class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stack = []
        
        for char in expression:
            if char == ')':
                expr = []
                while stack[-1] != '(':
                    expr.append(stack.pop())
                stack.pop()  # Remove the '('
                operator = stack.pop()
                
                if operator == '!':
                    # NOT operation
                    stack.append('t' if expr[0] == 'f' else 'f')
                elif operator == '&':
                    # AND operation
                    stack.append('t' if all(x == 't' for x in expr) else 'f')
                elif operator == '|':
                    # OR operation
                    stack.append('t' if any(x == 't' for x in expr) else 'f')
            elif char != ',':
                stack.append(char)
        
        return stack[-1] == 't'