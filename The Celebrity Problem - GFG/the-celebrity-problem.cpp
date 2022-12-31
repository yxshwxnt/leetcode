//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
    private:
    bool knows(vector<vector<int> >& M,int a,int b,int n){
        if(M[a][b]==1)
            return true; 
        else
            return false; 
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n){
        stack<int> st; 
        //step1: push all elements in stack 
        for(int i=0;i<n;i++){
            st.push(i); 
        }
        //step2: get 2 elements and compare them
        while(st.size()>1){
            int a=st.top(); 
            st.pop(); 
            int b=st.top(); 
            st.pop(); 
            if(knows(M,a,b,n)){
                st.push(b); 
            }
            else{
                st.push(a); 
            }
        }
        int ans=st.top(); 
        //step3: single element left in stack is potential candidate 
        bool rowCheck=false; 
        int zeroCnt=0; 
        for(int i=0;i<n;i++){
            if(M[ans][i]==0){   //it is celeb if it knows no one
                zeroCnt++; 
            }
        }
        if(zeroCnt==n) 
            rowCheck=true;  
        
        bool colCheck=false; 
        int oneCnt=0; 
        for(int i=0;i<n;i++){
            if(M[i][ans]==1){   //it is celeb if everyone knows him 
                oneCnt++; 
            }
        }
        if(oneCnt==(n-1))
            colCheck=true; 
        
        if(rowCheck==true && colCheck==true)   
            return ans; 
        else
            return -1; 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends