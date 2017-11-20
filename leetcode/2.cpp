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
    void SetCarry(ListNode* p, bool &carry){
        if(p->val>=10) {
            p->val -= 10;
            carry = 1;
        }
        else carry = 0;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1, *p2, *p, *q;
        ListNode *dummy_head;
        bool carry = 0;

        p1 = l1;
        p2 = l2;

        dummy_head = new ListNode(0);
        p = new ListNode(p1->val + p2->val);
        dummy_head->next = p;
        SetCarry(p, carry);

        while(p1->next && p2->next){
           p1 = p1->next;
           p2 = p2->next;
           q = new ListNode(p1->val + p2->val);
           p->next = q;
           if(carry) q->val += 1;  
           SetCarry(q, carry);
           p = q;
        }
        
        while(p1->next || p2->next){
            if(p1->next) {
                q = new ListNode(p1->next->val);
                p1 = p1->next;
            }
            else {
                q = new ListNode(p2->next->val);
                p2 = p2->next;
            }
            p->next = q;
            if(carry) q->val += 1;
            SetCarry(q, carry);
            p = q;
        }
        
        if(carry){
            q = new ListNode(1);
            p->next = q;
        } //last digit has carry
        return dummy_head->next;
    }
};
