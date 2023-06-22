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
// By using the sorting function and using an extra space vector. (Brute force solution)
// Time: O(N log N) where N is total no of nodes.
// space: O(N)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        vector<int>v;
        for(int i=0;i<lists.size();i++){
            ListNode *curr=lists[i];
            while(curr!=NULL){
                v.push_back(curr->val);
                curr=curr->next;
            } 
        }
        if(v.size()==0) return nullptr;
        sort(v.begin(),v.end());
        ListNode *temp=new ListNode (v[0]);
       ListNode *curr=temp;
        for(int i=1;i<v.size();i++){
            ListNode *temp1=new ListNode (v[i]);
            curr->next=temp1;
            curr=curr->next;
                
        }
        curr->next=NULL;
        return temp;
    }
};



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
// merge one by one 
// Time: O(kN) where k is the number of linked lists and N is the total number of nodes.
// Space: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a==NULL ) return b;
        if(b==NULL ) return a;
        ListNode *dummy=new ListNode (-1),*prev=dummy;
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
        if(a==NULL) prev->next=b;
        else prev->next=a;
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        ListNode* head = lists[0];
        for (int i = 1; i < lists.size(); i++)
            head = mergeTwoLists(head, lists[i]);
        return head;
    }
};



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
// Divide and conquer method
// Time: O(N log K) where k is the number of linked lists and N is the total number of nodes. log k will be the hight of the binary tree.
// Space: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a==NULL ) return b;
        if(b==NULL ) return a;
        
        ListNode *dummy=new ListNode (-1),*prev=dummy;
       
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
        
        if(a==NULL) prev->next=b;
        else prev->next=a;
               
        return dummy->next;
    }
    
    ListNode *mergeklistsDC(vector<ListNode *>&lists,int si,int ei){
        if(si>ei) return NULL;
        if(si==ei) return lists[si];
        int mid=(si+ei)/2;
        ListNode *l1=mergeklistsDC(lists,si,mid);
        ListNode *l2=mergeklistsDC(lists,mid+1,ei);
        // now merge these two Linked lists
        return mergeTwoLists(l1,l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        
       return mergeklistsDC(lists,0,lists.size()-1);
    }
};



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
// Using a min priority queue
// Time: O(N log K) where k is the number of linked lists and N is the total number of nodes.
// Space: O(N)
class comp{
    public:
    bool operator()(ListNode *a,ListNode *b){
        return a->val > b->val;
    }
};
class Solution {
public:
       ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *,vector<ListNode*>,comp>pq;
        for(auto l:lists) if(l!=NULL)pq.push(l);
        ListNode *dummy=new ListNode (-1);
        ListNode *prev=dummy;
        while(pq.size()!=0){
            ListNode *node =pq.top();
            pq.pop();
            prev->next=node;
            prev=prev->next;
            node=node->next;
            if(node!=NULL) pq.push(node);
        }
        return dummy->next;
    }
};
