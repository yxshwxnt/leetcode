//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.  
    long long merge(int s,int mid,int e,long long arr[]){
        long long cnt=0; 
        long long left=s; 
        long long right=mid+1;  
        
        vector<long long> temp; 
        while(left<=mid && right<=e){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]); 
                left++; 
            }
            else{
                temp.push_back(arr[right]); 
                right++;  
                cnt+=(mid-left+1); 
            }
        } 
        while(left<=mid){
            temp.push_back(arr[left]); 
            left++; 
        }
        while(right<=e){
            temp.push_back(arr[right]); 
            right++; 
        } 
        for(int i=s;i<=e;i++){
            arr[i]=temp[i-s]; 
        }
        return cnt; 
    }
    
    long long mergeSort(long long s,long long e,long long arr[]){
        long long cnt=0; 
        if(s>=e)  return cnt; 
        long long mid=(s+e)/2; 
        
        cnt+=mergeSort(s,mid,arr); 
        cnt+=mergeSort(mid+1,e,arr); 
        cnt+=merge(s,mid,e,arr);  
        
        return cnt; 
    }
     
    long long int inversionCount(long long arr[], long long N){
        return mergeSort(0,N-1,arr); 
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends