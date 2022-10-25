class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0; 
        int n=nums.size(); 
        
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i])     //if prev elem is greater than curr
                count++; 
        }
        if(nums[n-1]>nums[0])       //check if last element is greater than first
            count++; 
        
        return count<=1;            
    }
};