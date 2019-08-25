class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0, size = citations.size()-1;
        for(int i = size; i >= 0; --i) {
            if(h+1 <= citations[i]) ++h;
            else    break;
        }
        return h;
    }
};