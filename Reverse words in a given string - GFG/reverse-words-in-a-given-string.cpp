//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    string reverseWords(string s){ 
        string ans="";  
        vector<string> v; 
        int n=s.size(); 
        int i=0; 
        while(i<n){
            string w=""; 
            while(i<n && s[i]=='.'){
                i++; 
            }
            while(i<n && s[i]!='.'){
                w+=s[i++]; 
            }
            v.push_back(w); 
        }
        reverse(v.begin(),v.end());  
        ans+=v[0]; 
        for(int i=1;i<v.size();i++){
            ans+=("."+v[i]); 
        }
        return ans; 
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends