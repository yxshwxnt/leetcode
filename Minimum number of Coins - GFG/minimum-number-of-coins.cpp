//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        int denomination[]={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 }; 
        int size=sizeof(denomination)/sizeof(denomination[0]); 
        
        vector<int> ans; 
        for(int i=size-1;i>=0;i--){
            while(N>=denomination[i]){
                N-=denomination[i]; 
                ans.push_back(denomination[i]); 
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends