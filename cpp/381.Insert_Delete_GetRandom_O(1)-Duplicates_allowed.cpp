class RandomizedCollection {
private:
    vector<int> v;
    unordered_map<int, unordered_set<int>> m; 
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        v.push_back(val);
        m[val].insert(v.size()-1);
        return (m[val].size() == 1);            
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.count(val)) {
            int index = *m[val].begin();

            if(m[val].size() == 1) {
                m.erase(val);
            } else {
                m[val].erase(index);
            }

            if(index < v.size() - 1) {
                v[index] = v.back();
                m[v[index]].erase(v.size()-1);
                m[v[index]].insert(index);
            }

            v.pop_back();

            return true;
        }

        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ans = indices.find(val) == indices.end();
        indices[val].push_back(values.size());
        values.push_back({val, indices[val].size() - 1});
        return ans;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (indices.find(val) != indices.end()) {
            pair<int, int> p = values.back();
            int i = indices[val].back();
            indices[p.first][p.second] = i;
            if (indices[val].size() == 1) {
                indices.erase(val);
            } else {
                indices[val].pop_back();
            }
            values[i] = p;
            values.pop_back();
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return values[rand() % values.size()].first;
    }
private:
    unordered_map<int, vector<int>> indices;
    vector<pair<int, int>> values;
};