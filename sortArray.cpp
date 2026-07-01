# include <vector>
# include <queue>
using namespace std;

// Problem 33
// Problem 2 of Feb
// K Closest Points: MEDIUM
// Date: 03/02/26

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int& num: nums){
            pq.push(num);
        }

        vector<int> res;
        while (!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
