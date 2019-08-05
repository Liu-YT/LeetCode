/*
    线段树 + dfs
 */

class Solution {
public:
    struct Trie {
        bool isWord;
        vector<Trie*> child;
        Trie() : isWord(false), child(vector<Trie*>(26, nullptr)) {};
    };

    void dfs(vector<vector<char>>& board, vector<string>& ans, Trie* node, int i, int j, string cur) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        if(node == nullptr || board[i][j] == '#')   return;
        cur += board[i][j];
        if(node->isWord) {
            ans.push_back(cur);
        }
        char c = board[i][j];
        board[i][j] = '#';

        // up
        dfs(board, ans, node->child[board[i-1][j] - 'a'], i-1, j, cur);
        // down
        dfs(board, ans, node->child[board[i+1][j] - 'a'], i+1, j, cur);
        // left
        dfs(board, ans, node->child[board[i][j-1] - 'a'], i, j-1, cur);
        // right
        dfs(board, ans, node->child[board[i][j+1] - 'a'], i, j+1, cur);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size() == 0 || board[0].size() == 0)   return {};
        int m = board.size(), n = board[0].size();
        
        // 构造线段树
        Trie* root = new Trie();
        for(auto word : words) {
            Trie* node = root;
            for(auto c : word) {
                if(node->child[c - 'a'] == nullptr) {
                    node->child[c - 'a'] = new Trie();
                }
                node = node->child[c - 'a'];
            }
            node->isWord = true;
        }

        vector<string> ans;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dfs(board, ans, root->child[board[i][j] - 'a'], i, j, "");

        return ans;
    }
};