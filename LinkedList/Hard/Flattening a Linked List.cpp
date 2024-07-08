// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flattening-a-linked-list

Node *mergeLists(Node* a, Node* b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    
    Node* temp;
    if(a->data < b->data){
        temp = a;
        temp->bottom = mergeLists(a->bottom, b);
    } else{
        temp = b;
        temp->bottom = mergeLists(a, b->bottom);
    }
    
    return temp;
}
Node *flatten(Node *root) {
    
    if(root == NULL || root->next == NULL) return root;
    return mergeLists(root, flatten(root->next));
    // Your code here
}
