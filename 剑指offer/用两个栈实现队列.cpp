class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int ans = -1;
        if(!stack1.empty()) {
            while(!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            ans = stack2.top();
            stack2.pop();
            while(!stack2.empty()) {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        return ans;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};