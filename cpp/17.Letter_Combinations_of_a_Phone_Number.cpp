class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	if(digits.size() == 0) return {};
		vector<string> result;
		vector<string> num = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        queue<string> q;
		q.push("");
		while(!q.empty()) {
			string front = q.front();
			q.pop();

			if(front.size() < digits.size()) {
				for(auto c : num[digits[front.size()]-'0']) {
					q.push(front+c);
				}
			}
			else 
				result.push_back(front);

		}
		return result; 
    }
};