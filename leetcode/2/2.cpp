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
        ListNode* dummy_head;
        ListNode*p = l1, *q = l2;
        ListNode* pre_node;
        bool carry = 0;

        dummy_head = new ListNode(0); //in case o all null
        pre_node = dummy_head;

        while(p || q){
            int x = 0, y = 0;
            x = (p)? p->val : 0;
            y = (q)? q->val : 0;
            carry = (x + y ) / 10;
            int sum = x + y + carry;
            ListNode* node = new ListNode(sum % 10);
            pre_node->next = node;
            pre_node = node;

            if(x) x = x->next;
            if(y) y = y->next;
        }
         return dummy_head->next;
    }
};
