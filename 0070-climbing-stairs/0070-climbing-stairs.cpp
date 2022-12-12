class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1); 
        dp[0]=1;   //not jump; 
        dp[1]=1;   //jump 
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]; 
        }
        return dp[n]; 
    }
};