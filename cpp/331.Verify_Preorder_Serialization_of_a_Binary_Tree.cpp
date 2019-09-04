class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.size() == 0 || preorder == "#")
            return true;
        int i = 0, cnt = 1;
        for(i = 0; i < preorder.size(); ++i) {
            if(preorder[i] == ',') continue;
            
            if(preorder[i] == '#') {
                --cnt;
            }
            else {
                ++cnt; 
                while(i < preorder.size() && preorder[i] != ',') 
                    ++i;
            }

            if(cnt == 0)
                break;
        }

        return cnt == 0 && i == preorder.size()-1;
    }
};