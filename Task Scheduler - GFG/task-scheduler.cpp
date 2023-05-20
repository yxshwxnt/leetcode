//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        vector<int> freq(26); 
        for(auto it:tasks){
            freq[it-'A']++; 
        } 
        sort(freq.begin(),freq.end()); 
        int maxFreq=freq[25]-1; 
        int idleSlots=maxFreq*K; 
        for(int i=24;i>=0 && freq[i]>0;i--){
            idleSlots-=min(maxFreq,freq[i]); 
        } 
        return idleSlots>0 ? idleSlots+N : N; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends