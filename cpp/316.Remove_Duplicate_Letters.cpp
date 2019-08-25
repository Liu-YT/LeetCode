class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";

        map<char, int> m;
        for(auto c : s) 
            m[c]++;
        vector<bool> visited(26, false);
        stack<char> st;
        for(auto c : s) {
            m[c]--;
            if(visited[c - 'a'])    continue;
            while(!st.empty() && st.top() > c && m[st.top()] > 0) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            visited[c - 'a'] = true;
        }

        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};