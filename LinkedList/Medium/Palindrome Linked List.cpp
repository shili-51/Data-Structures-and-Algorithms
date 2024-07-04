// https://leetcode.com/problems/palindrome-linked-list/

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
    ListNode* reverseList(ListNode* head){
        if(head == NULL) return NULL;
        else if(head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }


    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        else if(head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseList(slow->next);
        ListNode* temp = newHead;
        while(temp != NULL){
            cout<<"temp"<<temp<<endl;
            temp = temp->next;
        }
        ListNode* first = head;
        ListNode* second = newHead;
        while(second != NULL){
            if(first->val  != second->val){
                slow->next = reverseList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        slow->next = reverseList(newHead);
        return true;        
    }
};
