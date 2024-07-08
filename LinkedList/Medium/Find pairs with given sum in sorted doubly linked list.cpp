// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-pairs-with-given-sum-in-doubly-linked-list

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        Node* curr = head;
        vector<pair<int,int>>ans;
        Node* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        
        int sum = 0;
        while(curr != tail && curr->data < tail->data){
            sum = curr->data + tail->data;
            if(sum > target){
                tail = tail->prev;
            }else if(sum < target){
                curr = curr->next;
            }else{
                pair<int,int>pq;
                pq.first = curr->data;
                pq.second = tail->data;
                ans.push_back(pq);
                curr = curr->next;
                tail = tail->prev;
            }
        }
        return ans;
    }
};
