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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* tail = reverse(head);
        if(n == 1) return reverse(tail->next);

        ListNode* cur = tail;
        ListNode* prev = nullptr;

        for(int i = 1; i < n; i++){
            prev = cur;
            cur = cur->next;
        }

        prev->next = cur->next;

        head = reverse(tail);
        return head;
    }

    ListNode* reverse(ListNode* node){

        ListNode* prev = nullptr;
        ListNode* cur = node;

        while(cur){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }
};
