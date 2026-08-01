# include <vector>
# include <queue>
using namespace std;

// Problem 25
// K-th Largest Element: HARD
// Date: 25/01/26

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x: nums){
            pq.push(x);

            if (pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};
