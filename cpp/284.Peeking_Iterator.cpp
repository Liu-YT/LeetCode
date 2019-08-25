// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    peeked = false;
        vec = nums;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!peeked) {
            peekVal = vec.front();
            vec.erase(vec.begin());
            peeked = true;
        }
        return peekVal;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
    int next() {
        int temp;
	    if(peeked){
            temp = peekVal;
            peekVal = NULL;
            peeked = false;
        }else{
            temp = vec.front(); 
            vec.erase(vec.begin());
        }
        return temp;
	}

	bool hasNext() const {
        return (vec.size()>0)||peeked;
	}
private:
    bool peeked;
    int peekVal;
    vector<int> vec;
};