// DFS + 递归
/*
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> v;
        map<string, multiset<string> > myMap;
        for(auto it : tickets)
        	myMap[it.first].insert(it.second);

        dfs("JFK", v, myMap);
        reverse(v.begin(), v.end());
        return v;
    }

    void dfs(string start, vector<string>& v, map<string, multiset<string> > &myMap) {
    	while(myMap[start].size() > 0) {
    		string next = *myMap[start].begin();
    		myMap[start].erase(myMap[start].begin());
    		dfs(next, v, myMap);
    	}
    	v.push_back(start);
    }
};
*/

// DFS + 迭代
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> v;
        map<string, multiset<string> > myMap;
        for(auto it : tickets)
        	myMap[it.first].insert(it.second);

        stack<string> myStack;
        myStack.push("JFK");
        while(!myStack.empty()) {
        	string node = myStack.top();
        	
        	if(!myMap[node].size()) {
        		myStack.pop();
        		v.push_back(node);
        	} 
        	else {
        		myStack.push(*myMap[node].begin());
        		myMap[node].erase(myMap[node].begin());
        	}
        }
        reverse(v.begin(), v.end());
        return v;
    }
};