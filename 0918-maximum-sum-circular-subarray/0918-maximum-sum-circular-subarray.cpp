class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax=0,currMin=0,maxSum=INT_MIN,minSum=INT_MAX,totalSum=0; 
        for(int x:nums){
            currMax=max(x,currMax+x);
            maxSum=max(maxSum,currMax);
            currMin=min(x,currMin+x); 
            minSum=min(minSum,currMin);
            totalSum+=x; 
        }
        return maxSum>0 ? max(maxSum,totalSum-minSum) : maxSum; 
    }
};