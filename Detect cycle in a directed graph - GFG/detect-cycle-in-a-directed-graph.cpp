//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	//Using topo Sort
	//Function to return list containing vertices in Topological order. 
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int> q; 
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i); 
	        }
	    }
	    int cnt=0; 
	    //o(v+e)
	    while(!q.empty()){
	        int node=q.front(); 
	        q.pop(); 
	        cnt++; 
	        //node is in your topo sort 
	        //so we remove it from indegree 
	        for(auto it:adj[node]){
	            indegree[it]--; 
	            if(indegree[it]==0){
	                q.push(it); 
	            }
	        }
	    }
	    if(cnt==V){
	        return false; 
	    }
	    return true; 
	}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends