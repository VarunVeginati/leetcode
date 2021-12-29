class MyHashMap {
public:
    vector<vector<pair<int,int> >> vec;
    
    MyHashMap() {
        vec = vector<vector<pair<int,int> >> (997);
    }
    
    void put(int key, int value) {
        vector<pair<int,int> > v = vec[key%997];
        bool is_key_available = false;
        for(int i=0; i<v.size(); i++) {
            if(v[i].first == key) {
                v[i].second = value;
                is_key_available = true;
            }
        }
        if(!is_key_available) v.push_back(make_pair(key,value));
        vec[key%997] = v;
    }
    
    int get(int key) {
        vector<pair<int,int> > v = vec[key%997];
        for(int i=0; i<v.size(); i++) {
            if(v[i].first == key) return v[i].second;
        }
        return -1;
    }
    
    void remove(int key) {
        vector<pair<int,int> > v = vec[key%997];
        for(int i=0; i<v.size(); i++) {
            if(v[i].first == key) {
                v.erase(v.begin()+i);
                break;
            }
        }
        vec[key%997] = v;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */