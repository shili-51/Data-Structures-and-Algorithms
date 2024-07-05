// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* A = headA;
        ListNode* B = headB;

        while(A != B){
            A = (A != NULL) ? (A->next) : headB;
            B = (B != NULL) ? (B->next) : headA;
        }

        return A;
        
    }
};
