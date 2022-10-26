class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        // [1] here, we store first seen indices for prefix sums (mod k);
        //    remainder 0 (when prefix sum equals k) is the only
        //    one that is allowed to occur just once, thus, we add 
        //    it to the map with index -1 (this won't break any logic)
        unordered_map<int,int> mp = {{0,-1}};
        int prefix_sum = 0;
        
        for (int i = 0; i < nums.size(); i++){
            prefix_sum+=nums[i]; 
            prefix_sum = prefix_sum% k;
            mp.insert({prefix_sum, i}); // insert only if not exists
            
            // [2] check the condition, namely, that the difference
            //    between two occurences of the same remainder is >= 2
            if (i - mp[prefix_sum] >= 2) 
                return true;
        }
        return false;
    }
};