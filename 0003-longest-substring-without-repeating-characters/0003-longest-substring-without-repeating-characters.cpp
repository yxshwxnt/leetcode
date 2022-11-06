class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);     //string can have 256 unique char 
        
        int left=0, right=0; 
        int n=s.size(); 
        int len=0; 
        while(right<n){
            if(mp[s[right]]!=-1){
                left=max(mp[s[right]]+1,left);     //agar value haamre map me hai toh index left                                                        agee shift kardo
            }
            mp[s[right]]=right;     //storing the index value
            len=max(len,right-left+1);     //+1 kyuki indexes hai l,r 
            right++; 
        }
        return len; 
    }
};