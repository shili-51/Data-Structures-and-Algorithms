// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicates-from-a-sorted-doubly-linked-list

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        Node* dummy = new Node(-1);
        dummy->next = NULL;
        dummy->prev = NULL;
        Node* temp = dummy;
        Node* curr = head;
        while(curr != NULL){
            if(curr->data != temp->data){
                temp->next = curr;
                curr->prev = temp;
                temp = curr;
            }
            curr = curr->next;
        }
        temp->next = NULL;
        head = dummy->next;
        head->prev = NULL;
        return head;
    }
};
