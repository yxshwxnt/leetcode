class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freqmap; 
        vector<int> freqVect; 
        
        for(int i=0;i<arr.size();i++){
            freqmap[arr[i]]++; 
        }
        
        for(auto i:freqmap){
            freqVect.push_back(i.second); 
        }
        
        sort(freqVect.begin(),freqVect.end()); 
        
        for(int i=0;i<freqVect.size()-1;i++){
            if(freqVect[i]==freqVect[i+1]){
                return false; 
            }
        }
        return true; 
    }
};