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
    
    ListNode *midNode(ListNode *head){
        if(head==NULL || head->next==NULL) return head;
        ListNode *slow =head;
        ListNode*fast= head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode *mergeList(ListNode *a,ListNode *b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode *dummy=new ListNode(-1);
        ListNode *prev=dummy;
        while(a!=NULL && b!=NULL){
            if(a->val<b->val){
                prev->next=a;
                a=a->next;
            }
            else{
                prev->next=b;
                b=b->next;
            }
            prev=prev->next;
        }
          if(a!=NULL) prev->next=a;
        else prev->next=b;
        return dummy->next;
        
     }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
       ListNode *mid=midNode(head);
        ListNode *nhead=mid->next;
        mid->next=NULL;
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(nhead);
        return mergeList(l1,l2);
    }
};
