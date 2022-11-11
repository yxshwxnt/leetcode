class Solution {
public:
    void recurPermute(int index,vector<int>& nums,vector<vector<int>>& ans){ 
        //srivers sheet prev problems
        if(index==nums.size()){
            ans.push_back(nums);    //agar size == len of index push and return
            return; 
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);   //haan sabse pehle (0,0), (1,1) aesa hoga 
            recurPermute(index+1,nums,ans);  
            swap(nums[index],nums[i]);    //wapas swap karenge jis se backtrack kar pae
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        recurPermute(0,nums,ans); 
        return ans; 
    }
};