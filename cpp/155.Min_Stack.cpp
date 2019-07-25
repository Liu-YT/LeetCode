class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minIndex = 0;
    }
    
    void push(int x) {
        nums.push_back(x);
        if(x < nums[minIndex]) {
            minIndex = nums.size() - 1;
        }
    }
    
    void pop() {
        if(minIndex == nums.size() - 1) {
            int tmp = 0;
            for(int i = 0; i < nums.size()-1; i++) {
                if(nums[tmp] > nums[i])  tmp = i;   
            }
            minIndex = tmp;
        }
        nums.pop_back();
    }
    
    int top() {
        return nums[nums.size()-1];
    }
    
    int getMin() {
        return nums[minIndex];
    }
private:
    int minIndex;
    vector<int> nums;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */