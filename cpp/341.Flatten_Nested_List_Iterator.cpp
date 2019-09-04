/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// memory limit
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto &item : nestedList) {
            helper(item);
        }
        
    }

    void helper(NestedInteger& item) {
        if(item.isInteger()) {
            nums.push_back(item.getInteger());
        }
        else {
            for (auto &i : item.getList())
                helper(i);
        }
    }

    int next() {
        if(cur < nums.size()) {
            return nums[cur++];
        }
        return -1;
    }

    bool hasNext() {
        return !(cur == nums.size());
    }
    static int cur;
private:
    vector<int> nums;
};

int NestedIterator::cur = 0;

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */


class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->nestedList = &nestedList;
    }

    int next() {
        int n = nums.front();
        nums.pop();
        return n;
    }

    bool hasNext() {
        while(nums.empty() && i < nestedList->size()) {
            if ((*nestedList)[i].isInteger()) {
                nums.push((*nestedList)[i].getInteger());
            }
            else {
                NestedIterator* it = new NestedIterator((*nestedList)[i].getList());
                while(it->hasNext()) nums.push(it->next());
            }
            ++i;
        }
        return !nums.empty();
    }
private:
    vector<NestedInteger>* nestedList;
    queue<int> nums;
    int i = 0;
};
