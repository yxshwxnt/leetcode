class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0; 
        if(word.size()==1)  return true; 
        for(auto x:word){
            if(isupper(x)) 
                cnt++; 
        }
        if(cnt==1 &&  isupper(word[0])) 
            return true; 
        if(cnt==0 ||  cnt==word.size()) 
            return true; 
        return false; 
    }
};