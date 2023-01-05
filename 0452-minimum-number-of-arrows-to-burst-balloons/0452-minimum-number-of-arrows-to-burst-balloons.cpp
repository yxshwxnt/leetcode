class Solution {
private: 
    static bool comp(vector<int> &a,vector<int> &b){    //we can also use lambda function 
        return a[1]<b[1]; 
    } 
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);   //sort according to end time p[][i]
        int arrows=1; 
        int last=points[0][1]; 
        for(int i=1;i<points.size();i++){
            if(points[i][0]>last){    //if starting is greater than (prev.) last 
                arrows++; 
                last=points[i][1];    //end time of other elem 
            }
        } 
        return arrows; 
    }
};