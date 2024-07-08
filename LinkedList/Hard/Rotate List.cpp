// https://leetcode.com/problems/rotate-list/

// find tail and connect tail to head, then point relevant node to null

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        int len = 1;
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k = k % len;
        k = len - k;
        ListNode* curr = head;
        for(int i = 0; i < k - 1; i++){
            curr = curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};
