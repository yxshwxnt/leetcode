class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //using hash set
        set<int> st; 
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]); 
        }
        int res=st.size(); 
        int j=0; 
        for(auto x:st){
            nums[j++]=x; 
        }
        return res; 
    }
};