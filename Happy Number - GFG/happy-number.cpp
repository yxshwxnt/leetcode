//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int nextNumber(int n){
        int ans=0; 
        while(n!=0){
            int x=n%10; 
            ans+=(x*x); 
            n/=10;
        } 
        return ans; 
    }
    int isHappy(int n){
        int slow=n; 
        int fast=nextNumber(n); 
        while(fast!=1 && slow!=fast){
            slow=nextNumber(slow);
            fast=nextNumber(nextNumber(fast)); 
        } 
        return fast==1; 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends