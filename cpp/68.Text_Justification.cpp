// 本题主要是控制输出形式，主要根据一定的规律实现即可，感觉算不上 hard
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int start = 0, end = 0, sum = 0;
        for(int i = 0; i < words.size(); ++i) {
            if(sum == 0) {
                sum += words[i].size();
                start = i;
            }
            else if(sum + words[i].size() + 1 <= maxWidth) {
                sum += words[i].size() + 1;
            }
            else {
                end = i - 1;
                int whitespace[end-start+1] = {0};
                if(start == end) whitespace[0] = maxWidth - sum;
                else if(maxWidth > sum) {
                    int temp = maxWidth - sum, j = 0;
                    while(temp > 0) {
                        whitespace[j % (end-start)]++;
                        ++j;
                        --temp;
                    }
                }
                string str = "";
                for(int k = start; k < end; ++k) {
                    str += words[k] + " ";
                    for(int m = 0; m < whitespace[k-start]; ++m)    str += " ";              
                }
                
                str += words[end];
                if(str.size() < maxWidth) {
                    for(int m = 0; m < whitespace[0]; ++m)    str += " ";              
                }

                result.push_back(str);
                sum = words[i].size();
                start = i;
            }
            if(i == words.size() - 1 && sum <= maxWidth) {
                string str = "";
                for(int k = start; k < words.size() - 1; ++k) {
                    str += words[k] + " ";
                }
                str += words[words.size()-1];
                if(str.size() < maxWidth) {
                    int size = maxWidth - str.size();
                    for(int m = 0; m < size; ++m)    str += " ";              
                }
                result.push_back(str);
            }
        }
        return result;
    }
};