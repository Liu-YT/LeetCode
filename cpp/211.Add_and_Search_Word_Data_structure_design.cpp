struct Node {
    Node *child[26];
    bool isWord;
    Node() : isWord(false) {
        for(auto &c : child)
            c = nullptr;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* cur = root;
        for(auto c : word) {
            if(!cur->child[c-'a'])
                cur->child[c-'a'] = new Node();
            cur = cur->child[c-'a'];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(root, word);        
    }

private:

    bool searchHelper(Node* node, string word) {
        if(!node)   return false;
        if(word == "") return node->isWord;
        if(word[0] == '.') {
            for(auto &c : node->child) {
                if(searchHelper(c, word.substr(1))) {
                    return true;
                }
            }
            return false;
        }
        return searchHelper(node->child[word[0]-'a'], word.substr(1));
    }

    Node* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */