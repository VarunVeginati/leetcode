class LRUCache {
public:
    struct DLL {
        int key;
        int value;
        DLL* next;
        DLL* prev;
        
        DLL(int k, int v, DLL* n, DLL* p) : key(k), value(v), next(n), prev(p) {}
    };
    
    DLL* head = new DLL(-1, -1, NULL, NULL);
    DLL* tail = new DLL(-2, -2, NULL, head);
    int cap;
    unordered_map<int, DLL*> m;
    
    LRUCache(int capacity) {
        head->next = tail;
        cap = capacity;
    }
    
    void addNode(int key, int value) {
        DLL* new_node = new DLL(key, value, head->next, head);
        head->next->prev = new_node;
        head->next = new_node;
        m[key] = new_node;
    }
    
    void removeNode(DLL* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        
        int val = m[key]->value;
        removeNode(m[key]);
        addNode(key, val);
        
        return val;
    }
    
    void put(int key, int value) {
        if(cap > 0) {
            if(m.find(key) == m.end()) {
                addNode(key, value);
                cap--;
            } else {
                removeNode(m[key]);
                addNode(key, value);
            }
        } else {
            if(m.find(key) == m.end()) { 
                m.erase(tail->prev->key);
                removeNode(tail->prev);
                addNode(key, value);
            } else {
                removeNode(m[key]);
                addNode(key, value);
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