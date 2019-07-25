class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> a = modifed(version1);
        vector<int> b = modifed(version2);
        for(int i = 0; i < min(a.size(), b.size()); i++) {
            if(a[i] > b[i])   return 1;
            if(a[i] < b[i])   return -1;
        }
        if(a.size() == b.size())    return 0;
        return (a.size() > b.size()) ? 1 : -1;
    }

    vector<int> modifed(string str) {
        int num = 0;
        vector<int> nums;
        str += '.';
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '.') {
                if(num == 0 && i == str.size()-1)   continue;
                nums.push_back(num);
                num = 0;
            }
            else {
                num = num * 10 + str[i] - '0';
            }
        }
        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i] == 0)    nums.pop_back();
            else break;
        }
        return nums;
    }
};