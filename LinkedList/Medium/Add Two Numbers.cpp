// https://leetcode.com/problems/add-two-numbers/

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
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        int sum = 0;
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(l1!=NULL || l2!=NULL)
        {
            int a = (l1==NULL) ? 0 : l1->val;
            int b = (l2==NULL) ? 0 : l2->val;
            sum = a + b + carry;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            carry = sum/10;
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        if(carry>0)
        {
            curr->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
