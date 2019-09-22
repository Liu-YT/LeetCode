class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> ans;

        if(num.size() == 0 || size == 0) {
            return ans;
        }

        deque<int> q;

        for(int i = 0; i < num.size(); i++) {
            while(!q.empty() && num[q.back()] <= num[i]) {
                q.pop_back();
            }

            while(!q.empty() && i - q.front() + 1 > size) {
                q.pop_front();
            }

            q.push_back(i);

            if(i+1 >= size) {
                ans.push_back(num[q.front()]);
            }
        }
        return ans;
    }
};