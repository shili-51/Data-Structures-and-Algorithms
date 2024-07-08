// https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int count = 0;
        ListNode* curr = head;
        while(curr!= NULL && count < k){
            count++;
            curr = curr->next;
        }
        if(count < k) return head;
        curr = head;
        count = 0;
        ListNode* prev = NULL;
        while(curr != NULL && count < k){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            count++;
        }
        head->next = reverseKGroup(curr,k);
        return prev;
    }
};
