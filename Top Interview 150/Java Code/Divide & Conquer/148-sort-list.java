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
class Solution {
      ListNode midNode(ListNode head){
        if(head==null || head.next==null) return head;
        ListNode slow =head;
        ListNode fast= head;
        while(fast.next!=null && fast.next.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    
      ListNode mergeList(ListNode a,ListNode b){
        if(a==null) return b;
        if(b==null) return a;
        ListNode dummy=new ListNode(-1);
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
    
    public ListNode sortList(ListNode head) {
       if(head==null || head.next==null) return head;
       ListNode mid=midNode(head);
        ListNode nhead=mid.next;
        mid.next=null;
        ListNode l1=sortList(head);
        ListNode l2=sortList(nhead);
        return mergeList(l1,l2); 
    }
}
