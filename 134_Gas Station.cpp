class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int preTank = 0;
        int tank = 0;
        int start = 0;
        for(int i = 0; i < size; ++i) {
        	tank += gas[i] - cost[i];
        	if(preTank < 0) {
        		start = i;
        		preTank = gas[i] - cost[i];
        	}
        	else {
        		preTank += gas[i] - cost[i];
        	}
        }
        return tank >= 0 ? start : -1;
    }
};