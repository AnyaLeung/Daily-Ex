/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p, *q, *node;
        ListNode *dummy_head;
        bool carry = 0;

        dummy_head = new ListNode(0);
        node = dummy_head;
        p = l1;
        q = l2;

        while(p || q){
            int x = (p==NULL)? 0 : p->val;
            int y = (q==NULL)? 0: q->val;
            int sum = x + y + carry;
            carry = sum / 10;
            node->next = new ListNode(sum % 10);
            node = node->next;

            if(p) p = p->next;
            if(q) q = q->next;
        }

        if(carry) node->next = new ListNode(1);

        return dummy_head->next;
    }
};
