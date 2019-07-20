class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for(int i = 0; i < wordList.size(); i++)
            words.insert(wordList[i]);
        if(!words.count(endWord))   return 0;

        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));

        while(!q.empty()) {
            string cur = q.front().first;
            int len = q.front().second;
            q.pop();
            vector<string> ngb = findNgb(cur, words);
            for(int i = 0; i < ngb.size(); i++){
                if(ngb[i] == endWord) return len+1;
                q.push(make_pair(ngb[i], len+1));
            }
        }
        return 0;
    }

    // 获取可以转换的单词
    // 遍历整个字典，将其中每个单词和当前单词比较，判断是否只差一个字符，时间复杂度 n*w，单纯数量*单词长度
    // vector<string> findNgb(string cur, unordered_set<string>& words) {
    //     vector<string> neigh;
    //     for(auto it = words.begin(); it != words.end();) {
    //         string word = *it;
    //         int diff = 0;
    //         for(int j = 0; j < cur.size(); j++) {
    //             if(word[j] != cur[j])    diff++;
    //         }
    //         if(diff == 1) {
    //             neigh.push_back(word);
    //             words.erase(it++);
    //         }
    //         else it++;
    //     }
    //     return neigh;
    // }

    // 遍历当前单词的每个字符x，将其改成a-z中除x的任意一个，形成新单词，判断是否在词典之中，复杂度：26*w
    vector<string> findNgb(string cur, unordered_set<string>& words) {
        vector<string> neigh;
        for(int i = 0; i < cur.size(); i++) {
            char x = cur[i];
            for(int j = 0; j < 26; j++) {
                cur[i] = 'a'+j;
                if(words.count(cur)) {
                    neigh.push_back(cur);
                    words.erase(cur);
                }
            }
            cur[i] = x;
        }
        return neigh;
    }
};