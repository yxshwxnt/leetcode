//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int f(int ind,int W,int val[],int wt[],vector<vector<int>>& dp){
        if(ind==0){
            if(wt[0]<=W)  return val[0]; 
            else return 0; 
        }
        if(dp[ind][W]!=-1)   return dp[ind][W]; 
        
        int notTake=0+f(ind-1,W,val,wt,dp); 
        int take=INT_MIN; 
        if(wt[ind]<=W){
            take=val[ind]+f(ind-1,W-wt[ind],val,wt,dp); 
        }
        return dp[ind][W]=max(take,notTake); 
    }
    int knapSack(int W, int wt[], int val[], int n){ 
       vector<vector<int>> dp(n,vector<int>(W+1,-1)); 
       return f(n-1,W,val,wt,dp); 
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends