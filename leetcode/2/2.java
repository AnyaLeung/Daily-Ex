/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy_head = new ListNode(0);
        ListNode pre_node = dummy_head;
        int carry = 0;

        while(l1!=null || l2!=null || carry!=0){
            int x = 0, y = 0;
            int sum = ((l2 == null) ? 0 : l2.val) + ((l1 == null) ? 0 : l1.val) + carry;
            /*
            x = (l1!=null)? l1.val : 0;
            y = (l2!=null)? l2.val : 0;
            int sum = l1 + l2 + carry;
            */
            carry = sum / 10;
            ListNode node = new ListNode(sum % 10);
            pre_node.next = node;
            pre_node = node;

            l1 = (l1 == null) ? l1 : l1.next;
            l2 = (l2 == null) ? l2 : l2.next;
        }
         return dummy_head.next;
    }
}

//Java 真難寫，真的，還醜。。
