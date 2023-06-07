//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s){
    string p=""; 
    for(int i=0;i<s.size();i++){
        int v=s.find(s[i]); 
        if(v>=0 && v<i){
            return p+s[i];
        } 
    } 
    return "-1"; 
}