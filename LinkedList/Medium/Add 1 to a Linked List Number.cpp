// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list

class Solution
{
    public:
    
    Node* reverseList(Node *head) {
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL){
            Node* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        if(head == NULL) return new Node(1);
        Node* newHead = reverseList(head);
        Node* curr = newHead;
        int num = curr->data + 1;
        int carry = num/10;
        if(carry == 0) curr->data = num;
        while(carry > 0 && curr->next != NULL){
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum/10;
            curr = curr->next;
        }
        if(carry != 0){
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum/10;
            if(carry > 0){
                Node* temp = new Node(carry);
                curr->next = temp;
                temp->next = NULL;
            }
        }
        head = reverseList(newHead);
        return head;
    }
};
