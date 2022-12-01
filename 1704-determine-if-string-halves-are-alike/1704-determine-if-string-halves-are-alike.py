class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vow=set('aeiouAEIOU')
        
        #count freq of vowels
        a=Counter(s[:len(s)//2])
        b=Counter(s[len(s)//2:])
        
        #sum of freqs
        sumA=sum(a[v] for v in vow)
        sumB=sum(b[v] for v in vow)
        
        #check if they are same
        return sumA==sumB