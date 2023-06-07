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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL) return head;
        if(left==1 && right==1) return head;
        
        ListNode *curr=head;
        ListNode *pre=NULL;
        while(left>1){
            pre=curr;
            curr=curr->next;
            left--;
            right--;
        }
        ListNode *con=pre,*tail=curr;
        while(right>0){
           ListNode *next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
            right--;
            
        }
        if(con!=NULL){
            con->next=pre;
        }
        else head=pre;
        tail->next=curr;
        return head;
    }
};
