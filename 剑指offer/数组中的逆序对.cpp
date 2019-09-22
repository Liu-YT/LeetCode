// 超时
class Solution {
public:
    int InversePairs(vector<int> data) {
        int size = data.size(), cnt = 0;
        for(int i = 0; i < size-1; i++) {
            for(int j = i+1; j < size; j++) {
                if(data[i] > data[j]) {
                    ++cnt;
                    cnt = cnt % 1000000007;
                }
            }
        }
        return cnt;
    }
};

// ac
class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() == 0){
            return 0;
        }
        // 排序的辅助数组
        vector<int> copy;
        for(int i = 0; i < data.size(); ++i){
            copy.push_back(data[i]);
        }
        return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
    }

    long InversePairsCore(vector<int> &data, vector<int> &copy, int begin, int end){
        // 如果指向相同位置，则没有逆序对。
        if(begin == end){
            copy[begin] = data[end];
            return 0;
        }
        // 求中点
        int mid = (end + begin) >> 1;
        // 使data左半段有序，并返回左半段逆序对的数目
        long leftCount = InversePairsCore(copy, data, begin, mid);
        // 使data右半段有序，并返回右半段逆序对的数目
        long rightCount = InversePairsCore(copy, data, mid + 1, end);

        int i = mid; // i初始化为前半段最后一个数字的下标
        int j = end; // j初始化为后半段最后一个数字的下标
        int indexcopy = end; // 辅助数组复制的数组的最后一个数字的下标
        long count = 0; // 计数，逆序对的个数，注意类型

        while(i >= begin && j >= mid + 1){
            if(data[i] > data[j]){
                copy[indexcopy--] = data[i--];
                count += j - mid;
            }
            else{
                copy[indexcopy--] = data[j--];
            }
        }
        for(;i >= begin; --i){
            copy[indexcopy--] = data[i];
        }
        for(;j >= mid + 1; --j){
            copy[indexcopy--] = data[j];
        }
        return leftCount + rightCount + count;
    }
};


// bug 
class Solution {
public:
    int cnt;

    int InversePairs(vector<int> data) {
        cnt = 0;

        if(data.size() != 0) {
            mergeSort(data, 0, data.size()-1);
        }
        return cnt;
    }

    void mergeSort(vector<int> data, int l, int r) {
        if(l < r) {
            int m = (l + r) >> 1;

            mergeSort(data, l, m);
            mergeSort(data, m + 1, r);

            merge(data, l, m, r);
        }

    }

    void merge(vector<int> data, int l, int m, int r) {
        vector<int>  t;

        int i = l;
        int j = m + 1;

        while(i <= m && j <= r) {
            if(data[i] > data[j]) {
                t.push_back(data[j++]);
                cnt = (cnt + (m - i + 1)) % 1000000007;
            }
            else {
                t.push_back(data[i++]);
            }
        }

        while(i <= m)   t.push_back(data[i++]);
        while(j <= r)   t.push_back(data[j++]);

        for(int i = 0; i < t.size(); i++)
            data[l + i] = t[i];
    }
};