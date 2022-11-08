//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool comaparator(Item a, Item b){
    double r1=(double)a.value/(double)a.weight;      //weight per value 
    double r2=(double)b.value/(double)b.weight;      
    return r1>r2;      //sort in descending order 
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        //sort According to value
        sort(arr,arr+n,comaparator); 
        
        int currWeight=0; 
        double finalValue=0.0; 
        
        for(int i=0;i<n;i++){
            if(currWeight+arr[i].weight<=W){
                currWeight+=arr[i].weight; 
                finalValue+=arr[i].value; 
            }
            else{
                int remain=W-currWeight;    //remain weight knapsack can carry
                finalValue+=(arr[i].value/(double)arr[i].weight)*(double)remain;   //unitary method se nikala
                break;       //fit nhi hora tabhi toh fractional value lerae hai 
            }
        }
        return finalValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends