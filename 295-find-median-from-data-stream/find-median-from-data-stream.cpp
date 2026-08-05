class MedianFinder {
public:
    priority_queue<int> left;

    priority_queue<
        int,
        vector<int>, 
        greater<int>
            > right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);

        if(left.size() > right.size()){
            right.push(left.top());
            left.pop();
        }

        if(left.top() > right.top()){
            int x = left.top(); left.pop();
            int y = right.top(); right.pop();

            left.push(y);
            right.push(x);

        }
    }
    
    double findMedian() {
        if(left.size() == right.size()) return (double)(left.top() + right.top())/2;
        else if(left.size() > right.size()) return left.top();
        return right.top();

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */