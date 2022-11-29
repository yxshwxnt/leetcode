class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> loss; 
        for(vector<int> v : matches){
            int x=v[0]; 
            int y=v[1]; 
            if(loss.count(x)==0){
                loss[x]=0; 
            }
            loss[y]++;
        }
        vector<int> noLoss,oneLoss; 
        for(auto it:loss){
            if(it.second==0){
                noLoss.push_back(it.first); 
            }
            else if(it.second==1){
                oneLoss.push_back(it.first); 
            }
        }
        return {noLoss,oneLoss}; 
    }
};