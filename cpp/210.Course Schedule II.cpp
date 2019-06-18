class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> v;
        int inDegree[numCourses] = {0}; // 记录课程需要先修课程的数量


        // 对应存储需要修完该课程才能修的课程
        vector<vector<int> > myVec(numCourses);
        for(auto it : prerequisites) {
            inDegree[it.first]++;
            myVec[it.second].push_back(it.first);
        }

        queue<int> q;

        for(int i = 0; i < numCourses; ++i) {
            if(inDegree[i] == 0) {
                v.push_back(i);
                q.push(i);
            }
        }

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                int tmp = q.front();
                q.pop();
                for (int j = 0; j < myVec[tmp].size(); ++j) {
                    inDegree[myVec[tmp][j]]--;
                    if(inDegree[myVec[tmp][j]] == 0) {
                        v.push_back(myVec[tmp][j]);
                        q.push(myVec[tmp][j]);
                    }
                }
            }
        }

        if(v.size() == numCourses) 
            return v;
        else {
            v.clear();
            return v;
        }
    }
};