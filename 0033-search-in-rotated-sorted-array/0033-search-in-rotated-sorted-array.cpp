class Solution {
public:
    
    
    int binarySearch(vector<int>& arr,int s,int e,int key){ 
        while(s<e){
            int mid=s+(e-s)/2; 
            if(arr[mid]==key){
                return mid; 
            }
            else if(key > arr[mid]){         
                s=mid+1; 
            }
            else{                       
                e=mid-1; 
            }
        }
        return -1;    
    }

    
    int search(vector<int>& nums, int k) {
        int n=nums.size();  
        int s=0,e=n-1; 
        long int mid=-1; 
        while(s<=e){
            int mid=s+(e-s)/2; 
            if(nums[mid]==k){
                return mid; 
            }
            if(nums[mid]>=nums[s]){
                // left sortef half 
                if(k>=nums[s] && k<nums[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1; 
                }
            }
            else{
                // right sorted array 
                if(k>nums[mid] && k<=nums[e]){
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