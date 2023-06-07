//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int k) {
        set<vector<int>> st;  
        int n=nums.size(); 
        sort(nums.begin(),nums.end()); 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int s=j+1; 
                int e=n-1; 
                while(s<e){
                    long long currSum=(long long)nums[i]+nums[j]+nums[s]+nums[e]; 
                    if(currSum==k){
                        st.insert({nums[i],nums[j],nums[s],nums[e]}); 
                        e--; 
                    } 
                    else if(currSum>k){
                        e--;
                    } 
                    else{
                        s++;
                    }
                }
            }
        } 
        vector<vector<int>> ans(st.begin(),st.end()); 
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends