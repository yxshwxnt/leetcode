class Solution {
public:
    //using stackk, see python more easier
    string removeDuplicates(string s) {
        string str; 
        for(char c:s){
            if(!str.empty() && str.back()==c){
                str.pop_back(); 
            }
            else{
                str.push_back(c); 
            }
        }
        return str;
    }
};