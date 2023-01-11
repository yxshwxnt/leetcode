class Solution {
public:
    int dfs(vector<int> adj[],vector<bool>& hasApple,int node,int parent){
        int dist=0;   ///tot time to collect apple from root 
        for(auto it:adj[node]){
            if(it!=parent){
                int temp=dfs(adj,hasApple,it,node);  //storing if root has apple or not 
                if(hasApple[it]){
                    dist += (2 + temp); //if root's child has an apple, we add 2, 1 for going, 1 for comming back  
                    hasApple[node]=true;   //hasApple[node] has been marked visited 
                }
            }
        }
        return dist; 
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n]; 
        //prepare adj. list 
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(adj,hasApple,0,0); 
    }
};