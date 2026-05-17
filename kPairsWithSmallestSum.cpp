# include <vector>
# include<algorithm>
# include <queue>
using namespace std;

// Problem 43
// Problem 13 of Feb
// Find K Pairs with Smallest Sums: MEDIUM
// Date: 17/02/26
// Time Complexity: O(k log min(n,k))

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k == 0) return res;

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < nums1.size() && i < k; i++){
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (k-- > 0 && !pq.empty()){
            auto top = pq.top(); pq.pop();
            int i = top.second.first;
            int j = top.second.second;
            
            res.push_back({nums1[i], nums2[j]});
            
            if (j + 1 < nums2.size()){
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }
        return res;
    }
};

// The logic to the pushing we did to that pq
// push the first k elements of each array
        // that is for each ith iteration 
        // we only push the number from the nums1 vec and the first number from the nums2 vec
        // ex  num1 = 1, 2, 3 and nums2 = 4, 5, 6
        // at the end of each iteration for k = 3
        // i = 0, push ({1 + 4}, {0, 0})
        // i = 1, push ({2 + 4}, {1, 0})
        // i = 2, push ({3, 4}, {2, 0})
        // so we see that we are only pushing the first k elements of nums1 into the heap and just the first elemt of the nums2 vec
