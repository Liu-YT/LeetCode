class MedianFinder {
public:
    struct Node {
        int val;
        Node* next;
        Node(int v) {
            val = v;
            next = nullptr;
        } 
    };

    /** initialize your data structure here. */
    MedianFinder() {
        head = new Node(-1);
        size = 0;
    }
    
    void addNum(int num) {
        ++size;
        Node* n = new Node(num);
        if(head->next == nullptr) {
            head->next = n;
        }
        else {
            Node* tmp = head;
            while(tmp->next && tmp->next->val < num) tmp = tmp->next;
            n->next = tmp->next;
            tmp->next = n;
        }
    }
    
    double findMedian() {
        int a, b;
        if(size % 2 == 0 && size > 0) {
            Node* tmp = head->next;
            for(int i = 1; i < size / 2; i++)
                tmp = tmp->next;
            a = tmp->val;
            b = tmp->next->val;
            return (a + b) * 1.0 / 2;
        }
        else {
            Node* tmp = head->next;
            for(int i = 1; i < (size+1) / 2; i++)
                tmp = tmp->next;
            a = tmp->val;
            return a * 1.0;
        }
    }

private:
    int size;
    Node* head;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */