class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        vector<int> n;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                n.push_back(nums[i]); 
                i++; 
            }
        }
        return n; 
    }
};