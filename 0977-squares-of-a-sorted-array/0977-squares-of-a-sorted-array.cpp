class Solution {
public:
    //10-12-22 rejected for 1000x O(1)
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size(); 
        int s=0; 
        int e=n-1; 
        
        vector<int> ans(n); 
        int pos=n-1; 
        while(s<=e){
            if(abs(nums[s])<abs(nums[e])){
                ans[pos--]=nums[e]*nums[e]; 
                e--; 
            }
            else{
                ans[pos--]=nums[s]*nums[s];
                s++; 
            }
        }
        return ans; 
    }
};