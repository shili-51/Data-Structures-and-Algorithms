// https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = odd->next;
        ListNode* first = odd;
        ListNode* second = even;
        while(second != NULL){
            first->next = second->next;
            if(second->next != NULL){
                first = second->next;
                second->next = first->next;
            }
            second = first->next;
        }
        first->next = even;
        return head;
    }
};

