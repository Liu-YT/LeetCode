// 染色法 + BFS

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    	int num = graph.size();
    	
    	bool colors[num] = {false};
    	int visited[num] = {0};

    	queue<int> q;
    	
    	for(int i = 0; i < num; ++i) {
    		if(graph[i].size() > 0 && visited[i] == 0) {
    			q.push(i);
    			visited[i] = 1;
		    	
		    	// bfs
		    	while(!q.empty()) {
		    		int top = q.front();
		    		q.pop();
		    		for(auto i : graph[top]) {
		    			if(!visited[i]) {
		    				visited[i] = 1;
		    				colors[i] = !colors[top];
		    				q.push(i);
		    			}
		    			if(colors[i] == colors[top])
		    				return false;
		    		}
		    	}
    		}
    	}

    	return true;
    }
};