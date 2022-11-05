/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //using fast and slow pointers O(N)   
        ListNode* start=new ListNode(); 
        start->next=head;           //start ka first is NUll and next is head
        ListNode* slow=start;
        ListNode* fast=start;
        for(int i=1;i<=n;i++){
            fast=fast->next; 
        }
        while(fast->next!=NULL){
            slow=slow->next; 
            fast=fast->next; 
        }
        ListNode* del=slow->next; 
        slow->next=slow->next->next;    //skipping the Nth Last Node 
        delete(del);              //if we want to delete the link(node) 
            
        return start->next;    //we have to return head of linked list
    }
};