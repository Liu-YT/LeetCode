class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	int add = 1;
    	vector<int> v;
    	for(int i = digits.size() - 1; i >= 0; --i) {
    		v.push_back((digits[i] + add) % 10);
    		add = (digits[i] + add) / 10;
    	}
    	if(add == 1)	v.push_back(add);
    	reverse(v.begin(), v.end());
    	return v;
    }
};