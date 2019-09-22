/*

构造一个最大堆和一个最小堆，最大堆用来存放较小的那一半的数据，最小堆用来存放较大的那一半的数据，
每次插入数据时与最大堆的堆顶进行比较，若比其小或相等，则插入最大堆，反之插入最小堆；
插入数据后需要平衡两个堆的大小，保证最大堆的大小永远与最小堆相等或多一，最后若两个堆的大小相等，则返回两个堆顶的平均值，若最大堆比最小堆多一，则返回最大堆的堆顶即可；
注意C++中最小堆和最大堆的定义格式。

 */

class Solution {
public:
    void Insert(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }

        if(maxHeap.size() == minHeap.size() + 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if(maxHeap.size() + 1 == minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double GetMedian() { 
        if(maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) * 1.0 / 2.0;
        }
        else {
            return maxHeap.top();
        }
    }
private:
    // 大根堆
    priority_queue<int, vector<int>, less<int>> maxHeap;

    // 小根堆
    priority_queue<int, vector<int>, greater<int>> minHeap;
};