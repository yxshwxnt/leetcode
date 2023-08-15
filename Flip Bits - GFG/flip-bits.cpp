//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n){
        int ones=0, zeros=0, maxZeros=0; 
        for(int i=0;i<n;i++){
            if(a[i]==1){
                ones++;
            } 
            if(zeros<0){
                zeros=0; 
            } 
            if(a[i]==0){
                zeros++;
            } 
            else{
                zeros--;
            } 
            maxZeros=max(maxZeros,zeros);
        } 
        return ones+maxZeros; 
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends