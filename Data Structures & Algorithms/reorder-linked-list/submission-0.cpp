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
    void reorderList(ListNode* head) {
        
        int length = 0;
        ListNode *cur = head;
        while(cur){
            length++;
            cur = cur->next;
        }

        //Count over halfway
        double halfway = ceil((double)length / 2);
        cur = head;
        ListNode* cur1 = head;
        //Stop one early to sever the two lists
        for(int i = 0; i < (int)halfway -1; i++){
            cur1 = cur1->next;
        }

        ListNode *tail = cur1;
        cur1 = cur1->next;
        tail->next = nullptr;

        cur1 = reverse(cur1);

        ListNode dummy = {};
        ListNode *res = &dummy;
        bool toggle = true;
        while(cur && cur1){
            if(toggle){
                res->next = cur;
                cur = cur->next;
            }else{
                res->next = cur1;
                cur1 = cur1->next;
            }
            res = res->next;
            toggle = !toggle;
        }
        if(cur) res->next = cur;
        else if(cur1) res->next = cur1;

        *head = *dummy.next;
    }

    ListNode* reverse(ListNode *head){
        
        ListNode *cur = head;
        ListNode *prev = nullptr;

        while(cur){
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }
};
