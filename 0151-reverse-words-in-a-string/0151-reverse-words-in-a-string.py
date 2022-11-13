class Solution:
    def reverseWords(self, s: str) -> str:
        s=s.split()     #splits words and creates an array
        s=s[::-1]       #reverses the array
        return ' '.join(s)   #joins the array with space in btwn
        