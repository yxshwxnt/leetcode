class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];          //using tortois(slow,fast) pointer method
        int fast=nums[0];  
        do{
            slow=nums[slow];        //slow=slow->next
            fast=nums[nums[fast]];    //fast=fast->next->next; 
        }while(slow!=fast); 
        
        fast=nums[0]; 
        while(slow!=fast){
            slow=nums[slow]; 
            fast=nums[fast]; 
        }
        return slow; 
    }
};