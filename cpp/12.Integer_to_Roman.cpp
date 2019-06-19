class Solution {
public:
    string intToRoman(int num) {
    	string romans[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    	int nums[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    	string ans = "";
    	for(int i = 0; i < 13; ++i) {
    		int count = num / nums[i];
    		while(count != 0) {
    			count--;
    			ans += romans[i];
    		}
    		num = num % nums[i];
    	}
    	return ans;
    }
};