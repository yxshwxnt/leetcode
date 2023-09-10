//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool solve(int n,int x){
        if(n%x==0)
            return false; 
        if(x>n)
            return true; 
        return solve(n-(n/x),x+1); 
    }
    bool isLucky(int n) { 
        //ALTERNATE METHOD 
        // for(int i=2;i<=n;i++){
        //     if(n%i==0){
        //         return false;
        //     } 
        //     n-=n/i; 
        // } 
        // return true; 
        return solve(n,2); 
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends