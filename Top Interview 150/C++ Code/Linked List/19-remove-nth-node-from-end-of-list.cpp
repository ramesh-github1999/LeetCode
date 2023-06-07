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
// Two Pass solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        if(head->next==NULL){
            if(n==0) return head;
            else return NULL;
        }
        ListNode *curr=head;
        int cnt=0;
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        if(cnt==n) return head->next;
        cnt-=n;
        curr=head;
        while(cnt>1){
            curr=curr->next;
            cnt--;
        }
        curr->next=curr->next->next;
        return head;
        }
};


// two pass solution (using dummy node)
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        if(head->next==NULL){
            if(n==0) return head;
            else return NULL;
        }
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *curr=head;
        int cnt=0;
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        cnt-=n;
        curr=dummy;
        while(cnt>0){
            curr=curr->next;
            cnt--;
        }
        curr->next=curr->next->next;
        return dummy->next;
        }
};


// One pass Solution (without using dummy nodes)
class Solution3 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* first = head;
        ListNode* second = head;
        for (int i = 0; i < n; i++) {
            first = first->next;
        }

        if (first == NULL)
            return head->next;

        while (first->next != NULL) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
        return head;
    }
};


// One pass solution (using dummy nodes)
class Solution4 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
         ListNode* first = dummy;
        ListNode* second = dummy;
        for (int i = 0; i <=n; i++) {
            first = first->next;
        }

        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
        return dummy->next;
    }
};
