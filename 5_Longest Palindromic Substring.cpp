/* 解法一 */

// class Solution {
// public:
//     string longestPalindrome(string s) {
//     	if(s.size() <= 1)	return s;
//        int len = 0;
//        int id = 0;
//        for(int i = 0; i < s.size() - 1; ++i) {
//        		if(s[i] == s[i+1]) 
//        			searchLongestPalindrome(i, i+1, id, len, s);
//        		searchLongestPalindrome(i, i, id, len, s);
//        } 
//        return s.substr(id, len);
//     }

//     void searchLongestPalindrome(int left, int right, int &id, int &len, string s) {
//     	while(left >= 0 && right < s.size() && s[left] == s[right]) {
//     		--left;
//     		++right;
//     	}
//     	int tmp = right - left - 1;
//     	if(tmp >= len) {
//     		id = left + 1;
//     		len = tmp;
//     	}
//     }
// };


/* 解法二 Manacher Algorithm 马拉车算法*/

class Solution {
public:
    string longestPalindrome(string s) {
    	string str = "$#";
    	for(int i = 0; i < s.size(); ++i) 
    		str = str + s[i] + "#";
    	int maxLen = -1;	// 最长回文子串的长度
    	int maxId = -1;	// 最长回文子串中心点的位置
    	int p[str.size()] = {};
    	int id = 0, mx = 0;

    	for(int i = 1; i < str.size(); ++i) {
    		if(i < mx)
    			p[i] = min(p[2 * id - i], mx - i);
    		else 
    			p[i] = 1;

    		while(str[i - p[i]] == str[i + p[i]])
    			p[i]++;

    		// 我们每走一步i，都要和mx比较，我们希望mx尽可能的远，这样才能更有机会执行if (i < mx)这句代码，从而提高效率
    		if(mx < i + p[i]) {
    			id = i;
    			mx = i + p[i];
    		}

    		if(p[i] - 1 > maxLen) {
    			maxLen = p[i] -1;
    			maxId = i;
    		} 			
    	}
		int start = (maxId - maxLen - 1) / 2; // 将最长回文子串起始位置转换回原串
		return s.substr(start, maxLen);
    }

};
