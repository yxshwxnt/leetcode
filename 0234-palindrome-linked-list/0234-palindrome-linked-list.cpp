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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev=NULL; 
        ListNode* next=NULL; 
        while(head!=NULL){
            next=head->next; 
            head->next=prev; 
            prev=head; 
            head=next;
        }
        return prev; 
    }
    
    bool isPalindrome(ListNode* head) {
        //base case if no element or single element in LL
        if(head==NULL || head->next==NULL)
            return true; 
        
        //Getting middle of LL
        ListNode* slow=head; 
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next; 
            fast=fast->next->next; 
        }
        
        //After getting middle reverse the right half 
        slow->next=reverseLL(slow->next); 
        slow=slow->next; 
        
        //ex: madam -> madma -> m=m, a=a , d 
        while(slow!=NULL){
            if(head->val!=slow->val){
                return false; 
            }
            head=head->next; 
            slow=slow->next; 
        } 
        return true; 
    }
};