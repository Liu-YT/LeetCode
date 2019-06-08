// 解法 1

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    	if(numCourses <= 1)	return true;
    		int n = numCourses;
        vector<set<int> > myVec(numCourses);
        for(auto it : prerequisites)
        	myVec[it.first].insert(it.second);

        queue<int> q;

        for(int i = 0; i < numCourses; ++i) {
            if(myVec[i].size() == 0)
                q.push(i);
        }

        while(!q.empty()) {
        	int size = q.size();
        	n -= size;
            for(int i = 0; i < size; ++i) {
                int tmp = q.front();
                q.pop();
                for (int j = 0; j < numCourses; ++j) {
                	if(j == tmp)	continue;
                	if(myVec[j].find(tmp) != myVec[j].end()) {
                		myVec[j].erase(myVec[j].find(tmp));
                    	if (myVec[j].size() == 0) 
                    		q.push(j);
                	}
                }
            }
        }

        if(n > 0)
        	return false;
        else
        	return true;
    }
};


// 解法 1 优化
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int inDegree[numCourses] = {0}; // 记录课程需要先修课程的数量

        // 对应存储需要修完该课程才能修的课程
        vector<set<int> > myVec(numCourses);
        for(auto it : prerequisites) {
            inDegree[it.first]++;
            myVec[it.second].insert(it.first);
        }

        queue<int> q;

        for(int i = 0; i < numCourses; ++i) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int size = q.size();
            numCourses -= size;
            for(int i = 0; i < size; ++i) {
                int tmp = q.front();
                q.pop();
                // 此处的引用很精髓！！！！
                for (auto &j : myVec[tmp]) {
                    inDegree[j]--;
                    if(inDegree[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }

        return numCourses == 0;
    }
};



// 解法 2
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<set<int> > myVec(numCourses);
        for(auto it : prerequisites)
        	myVec[it.second].insert(it.first);
        
        /*
        *	点的状态
        * 	-1 - 已被访问过，正在访问其后代节点
        *	 0 - 未被访问过
        *	 1 - 已被访问过，且其子节点亦全部访问过
        */
        int vertexState[numCourses] = {0};
        

        for(int i = 0; i < numCourses; ++i)
        	if(!dfs(i, myVec, vertexState))
        		return false;

        return true;
    }

    bool dfs(int node, vector<set<int> >& myVec, int *vertexState) {
    	if(vertexState[node] == 1)	return true;
    	vertexState[node] = -1;
    	for(int i : myVec[node]) {
    		if(vertexState[i] == -1)	return false;
    		if(!dfs(i, myVec, vertexState))	return false;
    	}
    	vertexState[node] = 1;
    	return true;
    }
};