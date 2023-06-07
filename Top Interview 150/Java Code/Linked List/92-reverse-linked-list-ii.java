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
    public ListNode reverseBetween(ListNode head, int left, int right) {
         if (head == null) return head;
        if (left == 1 && right == 1) return head;

        ListNode curr = head;
        ListNode pre = null;
        while (left > 1) {
            pre = curr;
            curr = curr.next;
            left--;
            right--;
        }
        ListNode con = pre, tail = curr;
        while (right > 0) {
            ListNode next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;
            right--;
        }
        if (con != null) {
            con.next = pre;
        } else {
            head = pre;
        }
        tail.next = curr;
        return head;
    }
}
