class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //using 2 pointers 
        if(nums.size()==0){
            return 0; 
        }
        
        //i will point to 0th indx and j points to next index
        int i=0; 
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){      //if both are unique then arr[++i]=arr[j]
                i++;                    //j moves and compare in every iteration 
                nums[i]=nums[j];  
            }
        }
        return i+1; 
    }
};