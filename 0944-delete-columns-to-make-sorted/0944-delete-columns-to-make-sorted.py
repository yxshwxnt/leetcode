class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        ans=0 
        for j in range(len(strs[0])):
            for i in range(1,len(strs)): 
                if strs[i][j]<strs[i-1][j]: 
                    ans+=1 
                    break 
        return ans                 
    