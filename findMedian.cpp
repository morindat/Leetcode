# include <queue>
# include <vector>
using namespace std;

// Problem 35
// Problem 4 of Feb
// Find the median of data stream: HARD
// Date: 04/02/26

class MedianFinder {
    priority_queue<int> low; // max heap to keep all elements that are less or equal to those in high
    priority_queue<int, vector<int>, greater<int>> high; // min heap

public:
    MedianFinder() {}

    void addNum(int num) {
        // push the num to the smaller heap
        low.push(num);
        high.push(low.top());
        low.pop();

        if (high.size() > low.size()) {
            low.push(high.top());
            high.pop();
        }
    }

    double findMedian() {
        if (low.size() == high.size()) {
            return (low.top() + high.top()) / 2.0;
        }
        return low.top();
    }
};


// More explicitely
/*
class MedianFinder {
public:
    priority_queue<int> low; // max heap
    priority_queue<int, vector<int>, greater<int>> high; // min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // add smaller numbers to the low heap and bigger to the to high heap
        if (low.empty() || num <= low.top()){
            low.push(num);
        } else {
            high.push(num);
        }

        // make sure size remain approx the same
        if (low.size() > high.size() + 1){
            high.push(low.top());
            low.pop();
        } else if (high.size() > low.size()){
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        if (low.size() == high.size()){
            return (low.top() + high.top()) / 2.0;
        } 
        return low.top();
    }
};

 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();

*/