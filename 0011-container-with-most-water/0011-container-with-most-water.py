class Solution:
    def maxArea(self, height: List[int]) -> int:
        # Optimized  
        ans=0 
        l,r=0,len(height)-1 
        while l<r: 
            area=(r-l) * min(height[l],height[r]) 
            ans=max(area,ans) 
            if height[l]<height[r]:
                l+=1 
            else:
                r-=1 
        return ans