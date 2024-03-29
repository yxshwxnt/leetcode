//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        long long ans=0; 
        int l=0, r=n-1; 
        long long maxLeft=0, maxRight=0; 
        while(l<=r){
            if(arr[l]<=arr[r]){
                if(arr[l]>=maxLeft){
                    maxLeft=arr[l]; 
                }
                else{
                    ans+=maxLeft-arr[l]; 
                }
                l++; 
            }
            else{
                if(arr[r]>=maxRight){
                    maxRight=arr[r]; 
                }
                else{
                    ans+=maxRight-arr[r]; 
                }
                r--; 
            }
        } 
        return ans; 
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends