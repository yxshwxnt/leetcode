//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool comparator(Job a,Job b){
    return (a.profit>b.profit);      //sorting according to maximum profit
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n){
        sort(arr,arr+n,comparator);
        int maxi=arr[0].dead; 
        for(int i=1;i<n;i++){
            maxi=max(maxi,arr[i].dead);     //finding the maximum deadline of Jobs
        }
        
        //Max Deadline+1 jitna arr bana lo  and set all indexes -1
        int slot[maxi+1];
        for(int i=0;i<maxi+1;i++){
            slot[i]=-1;  
        }
        
        int countJobs=0, jobProfit=0;           
        
        for(int i=0;i<n;i++){             //iterating through  Job DS
            for(int j=arr[i].dead;j>0;j--){    //iterating through array 
                if(slot[j]==-1) {            
                    slot[j]=i;            //set job profit in index if slot is -1 
                    countJobs++; 
                    jobProfit+=arr[i].profit;       //inc job profit
                    break; 
                }
            }
        }
        
        return {countJobs,jobProfit}; 
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends