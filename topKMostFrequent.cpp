# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;

// Problem 31
// Top K Most Frequent Elements: MEDIUM
// Date: 01/02/26

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // store every element in the map with its frequency
        unordered_map<int, int> mp;
        for (int num : nums){
            mp[num]++;
        }

        // min heap of (count, value)
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        for (auto &p : mp){
            pq.push({p.second, p.first});
            if (pq.size() > k){
                pq.pop();
            }
        }

        vector<int> res;
        while (!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
