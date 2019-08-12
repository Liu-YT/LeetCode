/*
多数投票升级版：

超过n/3的数最多只能有两个。先选出两个候选人A,B。 遍历数组，分三种情况：

1.如果投A（当前元素等于A），则A的票数++;

2.如果投B（当前元素等于B），B的票数++；

3.如果A,B都不投（即当前与A，B都不相等）,那么检查此时A或B的票数是否减为0：

    3.1 如果为0,则当前元素成为新的候选人；

    3.2 如果A,B两个人的票数都不为0，那么A,B两个候选人的票数均减一；

遍历结束后选出了两个候选人，但是这两个候选人是否满足>n/3，还需要再遍历一遍数组，找出两个候选人的具体票数。
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;

        if(nums.size() == 0)    return ans;

        int canA = nums[0], canB = nums[0];
        int countA = 0, countB = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == canA) {
                ++countA;
                continue;
            }

            if(nums[i] == canB) {
                ++countB;
                continue;
            }


            if(countA == 0) {
                canA = nums[i];
                countA++;
                continue;
            }

            if(countB == 0) {
                canB = nums[i];
                countB++;
                continue;
            }

            countA--;
            countB--;
        }

        int totalA = 0, totalB = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == canA)  ++totalA;
            else if(nums[i] == canB)  ++totalB;
        }

        if(nums.size() < totalA * 3)   ans.push_back(canA);
        if(nums.size() < totalB * 3)   ans.push_back(canB);
        return ans;
    }
};