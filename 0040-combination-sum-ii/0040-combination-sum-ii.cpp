class Solution {
public:
    void findCombinations(int ind,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>& ds){
        if(target==0){
            ans.push_back(ds); 
            return; 
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]){     //if i>ind matlab pehli bar nhi hai, ind is starting                                                     index
                continue; 
            }
            if(arr[i]>target){
                break; 
            }
            ds.push_back(arr[i]); 
            findCombinations(i+1,target-arr[i],arr,ans,ds); 
            ds.pop_back(); 
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        sort(candidates.begin(),candidates.end()); 
        vector<int> ds; 
        findCombinations(0,target,candidates,ans,ds); 
        return ans; 
    }
};