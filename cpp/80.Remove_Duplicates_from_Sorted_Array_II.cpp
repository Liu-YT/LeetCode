// 技巧题，主要思路使用一个变量统计当前有效的长度对应的下标位置和一个计数器相应出现的次数，对其进行处理就比较简单了
// 开始一直想着要把无效的位置对换这样卡了一下
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int len = 0, cnt = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[len]) {
                cnt = 1;
                nums[++len] = nums[i];
            }
            else if(nums[i] == nums[len]) {
                cnt++;
                if(cnt > 2) continue;
                nums[++len] = nums[i];
            }
        }
        return len+1;
    }
};