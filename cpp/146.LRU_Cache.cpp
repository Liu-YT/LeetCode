class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.count(key)) {
            auto iter = m[key];
            int value = iter->second;
            l.erase(iter);
            l.push_front(make_pair(key, value));
            m[key] = l.begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)) {
            l.erase(m[key]);
        } 
        else if(m.size() == capacity) {
            auto it = l.end();
            it--;   
            m.erase(it->first);
            l.erase(it);
        }    
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
    }
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */