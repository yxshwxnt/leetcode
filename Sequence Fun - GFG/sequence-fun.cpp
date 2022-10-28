//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		int NthTerm(int n){
		    long long mod=1e9+7; 
		    int i=1; 
		    long long ans=1; 
		    while(n--){
		        ans=(ans*i)+1; 
		        i++;
		        
		        ans=ans%mod; 
		    }
		    return ans%mod; 
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends