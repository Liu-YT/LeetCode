// 递归

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if(s1 == s2)	return true;
		if(s1.size() != s2.size())	return false;

		int size = s1.size();

		// 剪枝
		int letter[26] = {0};
		for(int i = 0; i < size; ++i) {
			letter[s1[i] - 'a'] ++;
			letter[s2[i] - 'a'] --;
		}
		for(int i = 0; i < 26; ++i) {
			if(letter[i] > 0)
				return false;
		}

		for(int k = 1; k < size; ++k) {
			if(isScramble(s1.substr(0, k), s2.substr(0, k)) && isScramble(s1.substr(k, size-k), s2.substr(k, size-k)))
				return true;
			if(isScramble(s1.substr(0, size-k), s2.substr(k, size-k)) && isScramble(s1.substr(size-k, k), s2.substr(0, k)))
				return true;
		}
		return false;
	}
};



// dp

class Solution {
public:
	bool isScramble(string s1, string s2) {

		if(s1.size() != s2.size())	return false;

		if(!s1.size())	return true;

		int size = s1.size();
		// s1_start, s2_start, match_len
		bool match[size][size][size+1];

		for(int i = 0; i < size; ++i)
			for(int j = 0; j < size; ++j)
				match[i][j][1] = (s1[i] == s2[j]);

		for(int len = 2; len <= size; ++len) 
			for(int i = 0; i <= size - len; ++i) 
				for(int j = 0; j <= size - len; ++j) {
					match[i][j][len] = false;	// initial
					for(int k = 1; k < len; ++k) 
						match[i][j][len] |= (match[i][j][k] && match[i+k][j+k][len-k]) \
											|| (match[i][j+len-k][k] && match[i+k][j][len-k]); 			
				}

		return match[0][0][size];
	}
};