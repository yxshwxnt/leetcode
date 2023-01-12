class Solution {
public:
    vector<int> ans; 
    void dfs(int node,int parent,vector<int>& count,vector<int> adj[],string &labels){
        for(auto it:adj[node]){
            if(it!=parent){
                vector<int> counting(26,0); 
                dfs(it,node,counting,adj,labels); 
                for(int i=0;i<26;i++){
                    count[i]=count[i]+counting[i];  //par node + child nodes freq. map
                }
            }
        }
        count[labels[node]-'a']++; 
        ans[node]=count[labels[node]-'a'];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n]; 
        for(auto it:edges){
            int u=it[0], v=it[1]; 
            adj[u].push_back(v); 
            adj[v].push_back(u); 
        }
        ans.resize(n,0); 
        vector<int> count(26,0);  
        dfs(0,-1,count,adj,labels); 
        return ans; 
    }
};