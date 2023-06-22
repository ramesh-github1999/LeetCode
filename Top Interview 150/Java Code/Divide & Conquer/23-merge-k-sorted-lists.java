/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// By using the sorting function and using an extra space vector. (Brute force solution)
// Time: O(N log N) where N is total no of nodes.
// space: O(N)
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        List<Integer>l=new ArrayList<>();
        for(ListNode ln:lists){
            while(ln!=null){
                l.add(ln.val);
                ln=ln.next;
            }
        }
        if(l.size()==0) return null;
        Collections.sort(l);
        ListNode temp=new ListNode (l.get(0));
       ListNode curr=temp;
        for(int i=1;i<l.size();i++){
            ListNode temp1=new ListNode (l.get(i));
            curr.next=temp1;
            curr=curr.next;
                
        }
        curr.next=null;
        return temp;
    }
}


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// merge list one by one.
// Time: O(kN) where k is the number of linked lists and N is the total number of nodes.
// Space: O(1)
class Solution {
    ListNode mergeTwoList(ListNode a,ListNode b){
        if(a==null) return b;
        if(b==null) return a;
        ListNode dummy=new ListNode (-1);
        ListNode prev=dummy;
        while(a!=null && b!=null){
            if(a.val<b.val){
                prev.next=a;
                a=a.next;
            }
            else{
                prev.next=b;
                b=b.next;
            }
            prev=prev.next;
        }
        if(a!=null) prev.next=a;
        else prev.next=b;
        return dummy.next;
        
    }
    
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length==0) return null;
        ListNode head=lists[0];
        for(int i=1;i<lists.length;i++){
            head=mergeTwoList(head,lists[i]);
        }
        return head;
    }
}


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// Divide and Conquer Method.
// Time: O(N log K) where k is the number of linked lists and N is the total number of nodes. log k will be the hight of the binary tree.
// Space: O(1)
class Solution {
    ListNode mergeTwoList(ListNode a,ListNode b){
        if(a==null) return b;
        if(b==null) return a;
        ListNode dummy=new ListNode (-1);
        ListNode prev=dummy;
        while(a!=null && b!=null){
            if(a.val<b.val){
                prev.next=a;
                a=a.next;
            }
            else{
                prev.next=b;
                b=b.next;
            }
            prev=prev.next;
        }
        if(a!=null) prev.next=a;
        else prev.next=b;
        return dummy.next;
        
    }
    
    ListNode mergeklistsDC(ListNode [] lists,int si,int ei){
        if(si>ei) return null;
        if(si==ei) return lists[si];
        int mid=(si+ei)/2;
        ListNode l1=mergeklistsDC(lists,si,mid);
        ListNode l2=mergeklistsDC(lists,mid+1,ei);
        // now merge these two Linked lists
        return mergeTwoList(l1,l2);
    }
    
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length==0) return null;
        
         return mergeklistsDC(lists,0,lists.length-1);
    }
}


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// using min priority queue
// Time: O(N log K) where k is the number of linked lists and N is the total number of nodes.
// Space: O(N)
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        // used lembda function (this-other) (pepcoding solution)
        PriorityQueue<ListNode> pq=new PriorityQueue<>((a,b)->{ 
            return a.val-b.val;
        });
         for(ListNode l:lists) if(l!=null)pq.add(l);
        ListNode dummy=new ListNode (-1);
        ListNode prev=dummy;
        while(pq.size()!=0){
            ListNode node =pq.remove();
            prev.next=node;
            prev=prev.next;
            node=node.next;
            if(node!=null) pq.add(node);
        }
        return dummy.next;
        
    }
}
