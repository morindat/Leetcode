# include <deque>
# include <vector>
using namespace std;

// Problem 54
// Problem 24 of Feb
// Sliding Window Max: HARD
// Date: 25/02/26

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++){
            // make sure no elements outside the window is in the deque
            if (!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            // remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            // now you can safely push in the index of the element
            dq.push_back(i);

            // add to result once the sliding window is complete
            if (i >= k - 1){
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};