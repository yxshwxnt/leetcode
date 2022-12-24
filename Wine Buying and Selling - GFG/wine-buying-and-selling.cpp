//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public: 
  //using greedy, 2 pointer
  long long int wineSelling(vector<int>& a, int n){
      int b=0, s=0; 
      long long ans=0; 
      while(b<n and s<n){
          while(a[b]<=0){   //jab tak buy neg. hai inc karo 
              b++; 
              if(b==n)   return ans; 
          } 
          while(a[s]>=0){   //jab tak sell pos. hai inc karo 
              s++; 
              if(s==n)   return ans; 
          } 
          if(abs(a[b])>=abs(a[s])){    //kharidne wale zyada hai 
              ans+= abs(b-s) * abs(a[s]); 
              a[b] += a[s];        //buying kam hai +(-s) se 
              a[s]=0;      //s 0 hoga, zare sell hojaenge 
          }
          else{    //bechne wale zyada hai 
              ans+= abs(b-s) * a[b];   //a[b] pos. hi hai 
              a[s] += a[b];        //buying kam hai +(-s) se 
              a[b]=0;      //s 0 hoga, zare sell hojaenge 
          }
      }  //continue karte rahe pure arr ke liye until b and s<n 
      return ans; 
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends