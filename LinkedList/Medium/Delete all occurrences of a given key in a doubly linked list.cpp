// https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* dummy = new Node();
        dummy->data = -1;
        dummy->next = NULL;
        dummy->prev = NULL;
        Node* temp = dummy;
        Node* curr = *head_ref;
        while(curr != NULL){
            if(curr->data != x){
                temp->next = curr;
                curr->prev = temp;
                temp = curr;
            }
            curr = curr->next;
        }
        temp->next = NULL;
        *head_ref = dummy->next;
    }
};
