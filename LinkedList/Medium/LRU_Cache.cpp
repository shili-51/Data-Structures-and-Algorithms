struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int _key, int _value){
        this->key = _key;
        this->val = _value;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache{
    private:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*>mp;

      // whenever there is a new insert - insert just after head;
    void insert(Node* node){
        // Insert in LinkedList
        Node* headNex = head->next;
        head->next = node;
        node->prev = head;
        node->next = headNex;
        headNex->prev = node;

    }

    // remove stale cache
    void deleteNode(Node* staleCache){
        
        // remove from linkedList
        Node* prevNode = staleCache->prev;
        Node* nextNode = staleCache->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;

    }

    public:
    LRUCache(int _capacity){
        this->capacity = _capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        mp.clear();
    }

    ~LRUCache(){};


    int get(int key){
        if(mp.find(key) == mp.end()) return -1;
        else{
            Node* targetNode = mp[key];
            int val = targetNode->val;
            deleteNode(targetNode);
            insert(targetNode);
            return val;
        }
    }

    void put(int key, int value){
        if(mp.find(key) != mp.end()){
            Node* targetNode = mp[key];
            targetNode->val = value;
            deleteNode(targetNode);
            insert(targetNode);
            return;
        }
        if(mp.size() == capacity){
            Node* targetNode = tail->prev;
            mp.erase(targetNode->key);
            deleteNode(targetNode);
        }
        Node* newNode = new Node(key, value);
        insert(newNode);
        mp.insert({key, newNode});
    }

};
