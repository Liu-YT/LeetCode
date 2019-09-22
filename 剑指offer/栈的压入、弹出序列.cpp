class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> s;
        int i = 0;
        for(auto &item : pushV) {
            s.push(item);
            while(!s.empty() && s.top() == popV[i]) {
                ++i;
                s.pop();
            }
        }
        return s.empty();
    }
};