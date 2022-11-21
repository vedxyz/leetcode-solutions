class Solution:
    def isValid(self, s: str) -> bool:
        mapping = { "(": ")", "[": "]", "{": "}" }
        stack = []
        for c in s:
            if c in mapping:
                stack.append(mapping[c])
            elif stack and stack[-1] == c:
                stack.pop()
            else:
                return False
                
        return len(stack) == 0

