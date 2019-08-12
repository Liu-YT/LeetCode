class Solution {
public:
    unordered_map<string, vector<int>> m;

    vector<int> diffWaysToCompute(string input) {

        if(m.count(input))  return m[input];

        int cnt = 0;
        vector<int> ans;

        for(int i = 0; i < input.size(); i++) {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*')  
                ++cnt;
        }

        if(cnt == 0) {
            ans.push_back(stoi(input));
            return ans;
        }

        for(int i = 0; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> a = diffWaysToCompute(input.substr(0, i));
                vector<int> b = diffWaysToCompute(input.substr(i+1));
                
                for(auto n1 : a) {
                    for(auto n2 : b) {
                        if(input[i] == '+') ans.push_back(n1 + n2);
                        if(input[i] == '-') ans.push_back(n1 - n2);
                        if(input[i] == '*') ans.push_back(n1 * n2);
                    }
                }
            }
        }
        return ans;
    }
};