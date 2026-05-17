#include <vector>
#include <stack>
using namespace std;

// Problem 49
// Problem 19 of Feb
// NGE 2: MEDIUM
// Date: 23/02/26

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;  // will store values

        // Traverse from 2n-1 down to 0
        for (int i = 2*n - 1; i >= 0; i--) {
            int num = nums[i % n];

            // Maintain decreasing stack
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }

            // Only fill answers during first pass
            if (i < n) {
                if (!st.empty()) {
                    ans[i] = st.top();
                }
            }

            st.push(num);
        }

        return ans;
    }
};