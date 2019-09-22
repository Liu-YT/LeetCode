class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k > input.size()){
            return {};
        }
        sort(input.begin(), input.end());
        input.resize(k);
        return input;
    }
};

// 超出内存
// partication
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k > input.size()) {
            return {};
        }

        int num = input[0];
        int i = 0, j = input.size()-1;
        while(i < j) {    
            while(i < j && input[j] > num) {
                j--;
            }
            input[i] = input[j];

            while(i < j && input[i] <= num) {
                i++;
            }
            input[j] = input[i];
        }
        input[i] = num;
        if(i == k) {
            vector<int> ans(input.begin(), input.begin()+i);
            sort(ans.begin(), ans.end());  
            return ans;
        }
        else if(i > k) {
            input.resize(i);
            return GetLeastNumbers_Solution(input, k);
        }
        else {
            vector<int> ans(input.begin(), input.begin()+i);
            vector<int> tmp(input.begin()+i, input.end());
            tmp = GetLeastNumbers_Solution(tmp, k - i);
            for(auto num : tmp) {
                ans.push_back(num);
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
    }
};

// 堆
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k > input.size() || k <= 0) {
            return {};
        }

        vector<int> heap(input.begin(), input.begin()+k);
        build_heap(heap);

        for(int i = k; i < input.size(); i++) {
            if(input[i] > heap[0]) {
                continue;
            }
            heap[0] = input[i];
            adjust_heap(heap, 0);
        }

        sort(heap.begin(), heap.end());
        return heap;
    }

    void build_heap(vector<int> &heap) {
        int size = heap.size();
        for(int i = size / 2 - 1; i >= 0; i--) {
            adjust_heap(heap, i);
        }
    }

    void adjust_heap(vector<int> &heap, int index) {
        while(index < heap.size()) {
            int i = index;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if(left < heap.size() && heap[left] > heap[i])
                i = left;
            if(right < heap.size() && heap[right] > heap[i])
                i = right;

            if(i == index)
                break;
            
            int tmp = heap[i];
            heap[i] = heap[index];
            heap[index] = tmp;

            index = i;
        }
    }
};

