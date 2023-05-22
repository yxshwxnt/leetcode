//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n){
        int ans1=0;
        int ans2=0; 
        int _xor=0; 
        for(int i=0;i<n;i++){
            _xor^=arr[i]; 
        }  
        //find right most set but;
        _xor=(_xor&(~(_xor-1))); 
        for(int i=0;i<n;i++){
            if(arr[i] & _xor){
                ans1^=arr[i]; 
            } 
            else{
                ans2^=arr[i]; 
            } 
        } 
        if(ans2>ans1){
            return {ans2,ans1}; 
        } 
        return {ans1,ans2}; 
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends