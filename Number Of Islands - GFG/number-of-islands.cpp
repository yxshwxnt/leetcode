//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet{
  vector<int> rank,size,parent; 
  public:
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
        if(node==parent[node])
            return node; 
        return parent[node]=findUPar(parent[node]); 
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
  private: 
    bool isValid(int row,int col,int n,int m){
        return (row>=0 && col>=0 && row<n && col<m); 
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m); 
        int vis[n][m]; 
        memset(vis,0,sizeof vis); //set all value as zero 
        int cnt=0;  
        vector<int> ans; 
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);  //if already visited just store cnt
                continue; 
            }
            vis[row][col]=1; 
            cnt++; 
            int dr[]={-1,0,+1,0}; 
            int dc[]={0,+1,0,-1}; 
            for(int i=0;i<4;i++){
                int adjR=row+dr[i];   //adjacent row
                int adjC=col+dc[i];    //adjacent col
                if(isValid(adjR,adjC,n,m)){
                    if(vis[adjR][adjC]==1){
                        int node=row*m + col;   //formula for getting nodeNumber 
                        int adjNode=adjR*m + adjC;  
                        if(ds.findUPar(node)!=ds.findUPar(adjNode)){   //if node doesn't belong to same comp. 
                            cnt--; 
                            ds.unionBySize(node,adjNode); 
                        }
                    }
                }
            }
            ans.push_back(cnt);   //append cnt in ans
        }
        return ans; 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends