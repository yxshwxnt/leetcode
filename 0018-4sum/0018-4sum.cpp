class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;  
        int n=nums.size(); 
        sort(nums.begin(),nums.end()); 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int start=j+1; 
                int end=n-1; 
                while(start<end){
                    long long crSum=(long long)nums[i]+nums[j]+nums[start]+nums[end]; 
                    if(crSum==target){
                        st.insert({nums[i],nums[j],nums[start],nums[end]}); 
                        end--; 
                    }
                    else if(crSum>target){
                        end--; 
                    }   
                    else{
                        start++;
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end()); 
        return ans; 
    }
};