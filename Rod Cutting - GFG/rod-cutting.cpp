//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int ind,int cut,int price[],vector<vector<int>>& dp){
        if(ind==0){
            return cut*price[0]; 
        }
        if(dp[ind][cut]!=-1)  return dp[ind][cut]; 
        
        int notCut=0+f(ind-1,cut,price,dp); 
        int rodLength=ind+1; 
        int doCut=-1e9; 
        if(rodLength<=cut){
            doCut=price[ind]+f(ind,cut-rodLength,price,dp); 
        }
        return dp[ind][cut]=max(doCut,notCut); 
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,-1)); 
        return f(n-1,n,price,dp); 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends