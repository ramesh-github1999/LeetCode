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
// two pass solution (using dummy node)
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) return head;
        if (head.next == null) {
            if (n == 0) return head;
            else return null;
        }
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode curr = head;
        int cnt = 0;
        while (curr != null) {
            curr = curr.next;
            cnt++;
        }
        cnt -= n;
        curr = dummy;
        while (cnt > 0) {
            curr = curr.next;
            cnt--;
        }
        curr.next = curr.next.next;
        return dummy.next;
    }
}


// One pass solution (without using dummy Nodes)
class Solution2 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode first=head,second=head;
        for(int i=0;i<n;i++){
            first=first.next;
        }
        if(first==null) return head.next;
            while(first.next!=null){
            first=first.next;
            second=second.next;
        }
        
       second.next=second.next.next;
        return head;
    }
}


// One pass solution ( using dummy Nodes)
class Solution3 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        ListNode first=dummy,second=dummy;
        for(int i=0;i<=n;i++){
            first=first.next;
        }
            while(first!=null){
            first=first.next;
            second=second.next;
        }
        
       second.next=second.next.next;
        return dummy.next;
    }
}
