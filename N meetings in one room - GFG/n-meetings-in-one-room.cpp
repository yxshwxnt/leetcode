//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct meeting{
    int start;
    int end; 
    int pos;
}; 
    
bool comparator(struct meeting m1,meeting m2){
    if(m1.end<m2.end){
        return true; 
    }
    else if(m1.end > m2.end){
        return false; 
    }
    else if(m1.pos < m2.pos){
        return true; 
    }
    return false; 
}

class Solution { 
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n){
        struct meeting meet[n];        //creating our own data structre than can store 3 values 
        for(int i=0;i<n;i++){
            meet[i].start=start[i];
            meet[i].end=end[i];
            meet[i].pos=i+1;     
        }
        
        sort(meet, meet+n, comparator);     //sort accoding to end time of meeting, if end time is same then sort acc. to position
        
        vector<int> ans; 
        
        int limit=meet[0].end; 
        ans.push_back(meet[0].pos); 
        
        for(int i=1;i<n;i++){
            if(meet[i].start>limit){
                limit=meet[i].end; 
                ans.push_back(meet[i].pos);
            }
        }
        
        return ans.size(); 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends