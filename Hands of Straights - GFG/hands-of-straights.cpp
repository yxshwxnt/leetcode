//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        map<int,int> mp; 
        for(auto it:hand){
            mp[it]++; 
        } 
        while(!mp.empty()){
            int first=mp.begin()->first; 
            for(int i=first;i<first+groupSize;i++){
                if(mp[i]==0){
                    return false; 
                } 
                mp[i]--; 
                if(mp[i]==0){
                    mp.erase(i); 
                }
            } 
        } 
        return true; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends