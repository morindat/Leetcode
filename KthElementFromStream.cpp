# include <queue>
# include <vector>
using namespace std;

// Problem 26
// K-th Largest Element From Stream: MEDIUM
// Date: 27/01/26
// Had a migraine yesterday and did not solve nothing, anyways i am making it up today and solve 2 problems

class KthLargest {
public:
    // A min heap
    // Keep adding elements as long as the heap is not > k
    // pop if greater
    
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums){
            pq.push(num);

            if (pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k){
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */