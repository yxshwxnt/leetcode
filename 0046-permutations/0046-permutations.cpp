class Solution {
public:
    void findPermutaion(vector<int>& ds,vector<int>& nums,vector<vector<int>>& ans,int freq[]){
        if(ds.size()==nums.size()){
            //agara size barabar length ke toh mtlab ans mil gaya return kardo
            ans.push_back(ds);
            return; 
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                //agar marked nhi hai toh add kardo
                ds.push_back(nums[i]); 
                freq[i]=1; 
                findPermutaion(ds,nums,ans,freq); 
                freq[i]=0; 
                ds.pop_back(); 
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        int freq[nums.size()]; 
        for(int i=0;i<nums.size();i++){
            freq[i]=0; 
        }
        findPermutaion(ds,nums,ans,freq); 
        return ans; 
    }
};