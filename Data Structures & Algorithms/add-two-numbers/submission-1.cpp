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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        int carry = 0;

        while(l1 || l2){
            int l1val, l2val;
            if(l1) l1val = l1-> val;
            else l1val = 0;
            if(l2) l2val = l2-> val;
            else l2val = 0;

            int sum = l1val + l2val;
            cur->next = new ListNode((sum + carry) % 10);
            cur = cur->next;
            carry = (sum + carry) / 10;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            
        }

        if(carry == 1) cur->next = new ListNode(1);

        return dummy->next;
    }
};
