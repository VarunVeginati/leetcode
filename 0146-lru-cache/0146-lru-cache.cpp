class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;
        
        Node(int k, int v, Node* n, Node* p): key(k), val(v), next(n), prev(p) {}
    };
    
    int cap;
    unordered_map<int, Node*> m;
    Node* head;
    Node* tail;
    
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1, NULL, NULL);
        tail = new Node(-1, -1, NULL, head);
        head->next = tail;
    }
    
    void addNode(Node* curr) {
        curr->next = head->next;
        curr->prev = head;
        head->next->prev = curr;
        head->next = curr;
    }
    
    void removeNode(Node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
        
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        
        Node* curr = m[key];
        removeNode(curr);
        addNode(curr);
        
        return curr->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            Node* curr = m[key];
            curr->val = value;
            removeNode(curr);
            addNode(curr);
        } else {
            if(cap>0) {
                Node* newNode = new Node(key, value, NULL, NULL);
                addNode(newNode);
                cap--;
                m[key] = newNode;
            } else {
                m.erase(tail->prev->key);
                removeNode(tail->prev);
                
                Node* newNode = new Node(key, value, NULL, NULL);
                m[key] = newNode;
                addNode(newNode);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */