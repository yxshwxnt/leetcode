class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels={'a','A','e','E','i','I','o','O','u','U'} 
        s=list(s)
        #using 2 pointers 
        left=0 
        right=len(s)-1
        while left<right:
            #moving until a vowel is found
            while left<right and s[left] not in vowels:
                left+=1 
            while left<right and s[right] not in vowels:
                right-=1 
            #swapping values of vowels
            s[left],s[right]=s[right],s[left] 
            left+=1 
            right-=1 
            
        return ''.join(s)