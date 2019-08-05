class TrieNode {

public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() : isWord(false) {
        for(auto &c : child)
            c = nullptr;
    }
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->child[word[i]-'a'] == nullptr) {
                node->child[word[i]-'a'] = new TrieNode();
            }
            node = node->child[word[i]-'a'];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->child[word[i]-'a'] == nullptr) {
                return false;
            }
            node = node->child[word[i]-'a'];
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i = 0; i < prefix.size(); i++) {
            if(node->child[prefix[i]-'a'] == nullptr) {
                return false;
            }
            node = node->child[prefix[i]-'a'];
        }
        return node == nullptr ? false : true;
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */