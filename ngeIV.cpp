#include <vector>
#include <stack>
using namespace std;

// Problem 55
// Problem 1 of March
// NGE IV: HARD
// Date: 04/03/26
// March just started, I owe Feb 4 questions and 3 for march

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> st1; // waiting for FIRST greater
        stack<int> st2; // waiting for SECOND greater

        for (int i = 0; i < n; i++) {

            // 1️⃣  Resolve SECOND greater
            while (!st2.empty() && nums[i] > nums[st2.top()]) {
                ans[st2.top()] = nums[i];
                st2.pop();
            }

            // 2️⃣  Move elements from st1 to st2 (FIRST greater found)
            stack<int> temp;  // use stack to preserve correct order
            while (!st1.empty() && nums[i] > nums[st1.top()]) {
                temp.push(st1.top());
                st1.pop();
            }

            while (!temp.empty()) {
                st2.push(temp.top());
                temp.pop();
            }

            // 3️⃣  Current index waits for FIRST greater
            st1.push(i);
        }

        return ans;
    }
};
