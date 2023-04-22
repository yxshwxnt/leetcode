//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    void getIpAdrresses(int ind,string s,vector<string>& ans,vector<string>& temp){
        if(ind==s.size() && temp.size()==4){
            string validIP=temp[0]+'.'+temp[1]+'.'+temp[2]+'.'+temp[3]; 
            ans.push_back(validIP); 
            return; 
        }
        string tempStr=""; 
        for(int i=ind;i<s.size() && temp.size()<4;i++){
            if(s[i]-'0'>9) continue; 
            tempStr+=s[i]; 
            int tempInt=stoi(tempStr); 
            if(tempInt>=0 && tempInt<=255){
                temp.push_back(tempStr); 
                getIpAdrresses(i+1,s,ans,temp); 
                temp.pop_back(); 
            }
            if(tempInt<=0 || tempInt>255){
                break; 
            }
        }
    }
    vector<string> genIp(string &s) {
       vector<string> ans; 
       vector<string> temp; 
       getIpAdrresses(0,s,ans,temp); 
       return ans; 
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends