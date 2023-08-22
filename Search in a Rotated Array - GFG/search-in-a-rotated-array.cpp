//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int nums[], int s, int e, int key){
        while(s<=e){
            int mid=s+(e-s)/2; 
            if(nums[mid]==key)
                return mid; 
            else if(nums[s]<=nums[mid]){
                if(key>=nums[s] && key<nums[mid]){
                    e=mid-1; 
                } 
                else{
                    s=mid+1;
                }
            } 
            else{
                if(key>nums[mid] && key<=nums[e]){
                    s=mid+1;
                } 
                else{
                    e=mid-1; 
                }
            }
        } 
        return -1; 
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends