class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return {0};
        vector<int> ans;
        vector<set<int> > myVec(n);
        for(auto edge : edges) {
            myVec[edge.first].insert(edge.second);
            myVec[edge.second].insert(edge.first);
        }
        queue<int> q;
        for(int i = 0; i < n; ++i)
            if(myVec[i].size() == 1)
                q.push(i);

        while(n > 2) {
            int size = q.size();
            n -= size;
            for(int i = 0; i < size; ++i) {
                int tmp = q.front();
                q.pop();
                for (auto it : myVec[tmp]) {
                    myVec[it].erase(tmp);
                    if (myVec[it].size() == 1) q.push(it);
                }
            }
        }

        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
