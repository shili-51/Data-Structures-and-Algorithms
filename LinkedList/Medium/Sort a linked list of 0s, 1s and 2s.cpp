// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it

class Solution
{
    public:
    Node* segregate(Node *head) {
        if(head == NULL || head->next == NULL) return head;
      
        Node* curr = head;
        Node* zeroD = new Node(0);
        Node* oneD = new Node(0);
        Node* twoD = new Node(0);
        Node* zero = zeroD;
        Node* one = oneD;
        Node* two = twoD;
        
        while(curr != NULL){
            
            if(curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } 
            
            else if(curr->data == 1) {
                one->next = curr;
                one = one->next;
            }
            else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
            
        }
        

        zero->next = (oneD->next != NULL) ? (oneD->next) : (twoD->next);
        one->next = twoD->next;
        two->next = NULL;
        
        head = zeroD->next;
        
        delete(zeroD);
        delete(oneD);
        delete(twoD);
        
        return head;
        
    }
};
