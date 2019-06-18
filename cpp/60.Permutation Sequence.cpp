class Solution {
public:
    string getPermutation(int n, int k) {
    	string res = "";
    	bool isVis[n] = { false };
    	sol(res, n, isVis, k);
    	return res;
    }

	void sol(string& res, int nums, bool *isVis, int k) {
    	if(nums == res.size()) {
    		return;
    	}

    	int count = 1;
    	// (n-size)!
    	for(int i = 1; i < nums - res.size(); ++i)	count *= i;
    	
    	int a = (k - 1) / count;
		for(int i = 0; i < nums; ++i) {	
			if(!isVis[i]) {
				if(a > 0)	--a;
				else {
					res += 1 + i + '0';
					isVis[i] = true;
					sol(res, nums, isVis, k - ((k - 1) / count) * count);
					return;
				}
			} 
		}
    }
};