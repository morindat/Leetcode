# include <unordered_set>
# include <queue>
using namespace std;

// Problem 28
// thirdMax: EASY
// Date: 27/01/26
// So I skipped one day and solved three today, should be enough attornment, right?

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) continue;   // skip duplicates

            pq.push(num);
            seen.insert(num);

            if (pq.size() > 3) {
                seen.erase(pq.top());
                pq.pop();
            }
        }

        if (pq.size() == 3) return pq.top();

        // fewer than 3 distinct → return max
        while (pq.size() > 1) pq.pop();
        return pq.top();
    }
};
