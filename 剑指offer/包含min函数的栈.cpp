class Solution {
public:
    void push(int value) {
        if(v.empty()) {
            minNum = value;
        }
        if(value < minNum) {
            minNum = value;
        }
        v.push_back(value);
    }

    void pop() {
        if(!v.empty()) {
            if(top() == minNum) {
                if(!v.empty())
                    minNum = v[0];
                for(int i = 0; i < v.size()-1; i++) {
                    if(v[i] < minNum) {
                        minNum = v[i];
                    }
                }
            }
            v.pop_back();
        }
    }
    
    int top() {
        return v.back();
    }
    
    int min() {
        return minNum;
    }

private:
    int minNum;
    vector<int> v;
};