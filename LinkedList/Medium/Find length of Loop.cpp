// https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop

// first go to starting node of loop
// then start counting from there till we reach back again to start of Loop

Node* firstNodeLoop(struct Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            isCycle = true;
            break;
        }
    }
    if(isCycle == true){
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;
}

int countNodesinLoop(struct Node *head)
{
    if(head == NULL) return 0;
    else if(head->next == NULL) return 0;
    int count = 1;
    Node* start = firstNodeLoop(head);
    if(start == NULL) return 0;
    else{
        Node* curr = start->next;
        while(curr != start){
            count++;
            curr = curr->next;
        }
    }
    return count;
}
