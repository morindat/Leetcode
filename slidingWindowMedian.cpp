#include <vector>
#include <queue>
# include <unordered_map>
using namespace std;

// Problem 47
// Problem 17 of Feb
// Sliding Window Median: HARD
// Date: 21/02/26


class Solution {
private:
    // maxHeap for the lower half and minHeap for the upper half
    priority_queue<int> minHeap;
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    
    // Map to track elements pending removal
    // [num, freq]
    unordered_map<int, int> delayed;
    
    // Logical sizes of the heaps (excluding delayed elements)
    int low_size = 0;
    int high_size = 0;

    // Prune invalid elements from the top of the heap
    void prune(priority_queue<int>& heap) {
        while (!heap.empty()) {
            int num = heap.top();
            // check if the num is in the map alr
            // and if it appeared more than 0 times
            if (delayed.count(num) && delayed[num] > 0) {
                // if it did, gladly lower it freq
                delayed[num]--;
                // if it does not appear anymore in the map
                // just delete it and pop
                if (delayed[num] == 0) delayed.erase(num);
                heap.pop();
            } else {
                break;
            }
        }
    }
    
    // similar, but for the min heap
    void prune(priority_queue<int, vector<int>, greater<int>>& heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (delayed.count(num) && delayed[num] > 0) {
                delayed[num]--;
                if (delayed[num] == 0) delayed.erase(num);
                heap.pop();
            } else {
                break;
            }
        }
    }

    // Rebalance heaps to ensure low_size == high_size or low_size == high_size + 1
    void rebalance() {
        if (low_size > high_size + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            low_size--;
            high_size++;
            prune(minHeap);
        } else if (high_size > low_size) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            high_size--;
            low_size++;
            prune(maxHeap);
        }
    }

    void add_num(int num) {
        if (minHeap.empty() || num <= minHeap.top()) {
            minHeap.push(num);
            low_size++;
        } else {
            maxHeap.push(num);
            high_size++;
        }
        rebalance();
    }

    void remove_num(int num) {
        delayed[num]++;
        
        // Determine which heap the number logically belongs to based on current tops
        // Note: We compare with minHeap.top() because minHeap holds the smaller half
        if (num <= minHeap.top()) {
            low_size--;
            if (num == minHeap.top()) prune(minHeap);
        } else {
            high_size--;
            if (num == maxHeap.top()) prune(maxHeap);
        }
        rebalance();
    }

    double get_median(int k) {
        if (k % 2 == 1) {
            return (double)minHeap.top();
        } else {
            return ((double)minHeap.top() + (double)maxHeap.top()) / 2.0;
        }
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        
        // Initialize first window
        for (int i = 0; i < k; ++i) {
            add_num(nums[i]);
        }
        result.push_back(get_median(k));
        
        // Slide window
        for (int i = k; i < nums.size(); ++i) {
            add_num(nums[i]);
            remove_num(nums[i - k]);
            result.push_back(get_median(k));
        }
        
        return result;
    }
};