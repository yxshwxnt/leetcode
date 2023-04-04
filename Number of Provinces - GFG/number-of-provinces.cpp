//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DisjointSet{
    public: 
    vector<int> size,rank,parent; 
    DisjointSet(int n){
        rank.resize(n+1,0); 
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i]=i; 
            parent[i]=i; 
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]); 
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u); 
        int ulp_v=findUPar(v); 
        if(ulp_u==ulp_v)   return; 
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v; 
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u; 
        }
        else{
            parent[ulp_v]=ulp_u; 
            rank[ulp_u]++; 
        }
    } 
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u); 
        int ulp_v=findUPar(v); 
        if(ulp_u==ulp_v)  return; 
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v; 
            size[ulp_v]+=size[ulp_u]; 
        }
        else{
            parent[ulp_v]=ulp_u; 
            size[ulp_u]+=size[ulp_v]; 
        }
    }
}; 

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V); 
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    //i and j 
                    ds.unionBySize(i,j); 
                }
            }
        } 
        int cnt=0; 
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i)  cnt++; 
        }
        return cnt; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends