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
    ListNode* rotateRight(ListNode* head, int k) {
        //Edge Case 
        if(head==NULL || head->next==NULL || k==0){
            return head; 
        }
        
        ListNode* curr=head; 
        int len=1; 
        while(curr->next!=NULL){    //travese the linked list and find last node 
            curr=curr->next; 
            len++; 
        }
        //point last node to head(cyclic LL)
        curr->next=head; 
        k=k%len;      //if k>=len eq: 12%5==2 --> rotate by 2
        k=len-k;      //finding length of LL that has to not be roteted
        while(k--){
            curr=curr->next; 
        }
        head=curr->next;       //decting rotated elem
        curr->next=NULL;       //removing cycle of LL
         
        return head;        
    }
}; 