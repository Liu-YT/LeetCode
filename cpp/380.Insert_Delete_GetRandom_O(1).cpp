class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.count(val)) {
            return false;
        }
        s.insert(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.count(val)) {
            s.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int ran = random() % s.size();
        for(auto item : s) {
            if(ran == 0) {
                return item;
            }
            --ran;
        }
        return *(s.begin());
    }
private:
    unordered_set<int> s;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


class RandomizedSet {
private:
    int n;
    vector<int> cache;
    unordered_map<int, int> mp; 
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        n = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val)) {
            return false;
        }
        
        if(cache.size() == n) {
            cache.push_back(val);
        }
        else {
            cache[n] = val;
        }

        mp[val] = n++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.count(val)) {
            cache[mp[val]] = cache[n-1];
            mp[cache[n-1]] = mp[val];
            mp.erase(val);
            --n;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int ran = random() % n;
        return cache[ran];
    }
};