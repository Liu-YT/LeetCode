/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> v;
    	if(intervals.size() == 0) {
    		v.push_back(newInterval);
    		return v;
    	}

        bool isAdd = false;
        for(int i = 0; i < intervals.size(); ++i) { 
        
        	if(intervals[i].start > newInterval.end) {
        		if(!isAdd) v.push_back(newInterval);
        		v.push_back(intervals[i]);
        		isAdd = true;
        	}
    		else if(intervals[i].end < newInterval.start) {
    			v.push_back(intervals[i]);
    		}
    		else {
    			newInterval.start = min(newInterval.start, intervals[i].start);
    			newInterval.end = max(newInterval.end, intervals[i].end);
    		}
    	}
    	if(!isAdd) v.push_back(newInterval);
    	return v;
    }
};