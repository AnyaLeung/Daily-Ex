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
        ListNode* p = l1, *q = l2;
        ListNode* res, *pre;
        ListNode* dummy_head = new ListNode(0);
        bool carry = false; //dont carry
        
        pre = dummy_head;
        while(p!=NULL || q!=NULL){
            //res *= 10;
            int digit = 0;
            digit = (p==NULL)? *q+carry : *p+*q+carry;
            digit = (q==NULL)? *p+carry : *p+*q+carry;
            //for added n addi diff digit no

            if(digi>10) {
                carry = true;
                digit -= 10;
            }
            ListNode ne_no = new ListNode(digit);
            pre->next = ne_no;

            p = p->next;
            q = q->next;
        }
            return dummy_head->next;
    }
};
