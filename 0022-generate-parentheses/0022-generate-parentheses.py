class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # only add open paranthesis if open < n
        # only add a close paran. if close < open 
        # valid iff open == closed == n  
        stack=[]
        ans=[]
        def backtrack(openN,closedN):
            if openN==closedN==n:
                ans.append("".join(stack))
                return  
            if openN < n:
                stack.append("(")
                backtrack(openN+1,closedN)
                stack.pop()
            if closedN < openN:
                stack.append(")")
                backtrack(openN,closedN+1)
                stack.pop()

        backtrack(0,0)
        return ans 