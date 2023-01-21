class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> temp; 
        vector<string> ans;
        getIPAddresses(temp,ans,s,0); 
        return ans;  
    }
    void getIPAddresses(vector<string>& temp,vector<string>& ans,string s,int index){
        if(index==s.length() && temp.size()==4){
            string validIP=temp[0]+'.'+temp[1]+'.'+temp[2]+'.'+temp[3]; 
            ans.push_back(validIP); 
            return; 
        } 
        string tempStr=""; 
        for(int i=index;i<s.length() && temp.size()<4;i++){
            if(s[i]-'0'>9)  continue; 
            tempStr+=s[i]; 
            int tempInt=stoi(tempStr); 
            if(0<=tempInt && tempInt<=255){
                temp.push_back(tempStr); 
                getIPAddresses(temp,ans,s,i+1); 
                temp.pop_back();  
            }
            if(tempInt<=0 || tempInt>255){   
                break; 
            }
        }
    }
};