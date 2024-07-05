// https://leetcode.com/problems/sort-list/

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

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        if(l1->val > l2->val) return merge(l2,l1);
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        if(l1 != NULL) temp->next = l1;
        else temp->next = l2;
        return dummyNode->next;
    }

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;

        // for getting first mid from Linked List in case there are 2 mids
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        // find mid node
        ListNode* mid = findMid(head);
        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = NULL;

        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);

        return merge(leftHead, rightHead);
    }

    ListNode* sortList(ListNode* head) {
        // if(head == NULL) return NULL;
        // else if(head->next == NULL) return head;
        ListNode* newHead = mergeSort(head);
        return newHead;
    }
};
