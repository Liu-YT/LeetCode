class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    	if(intervals.size() <= 1)	return intervals;
    	sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){
    		return v1[0] < v2[0];
    	});
    	vector<vector<int>> res;
    	vector<int> v = intervals[0];
    	for(int i = 1; i < intervals.size(); ++i) {
    		if(intervals[i][0] > v[1]) {
    			res.push_back(v);
    			v = intervals[i];
    		}
    		else {
    			v[1] = max(v[1], intervals[i][1]);
    		}
			if(i == intervals.size() - 1)	res.push_back(v);	
    	}
    	return res;
    }
};