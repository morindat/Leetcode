# include <vector>
# include<algorithm>
# include <queue>
using namespace std;

// Problem 40
// Problem 10 of Feb
// Maximum Perfomance: HARD
// Date: 16/02/26
// Similar to minimum cost problem, lol
// O(n log n): Paid by sorting
// Suppose we have some GOD given sorting AlGO that can get the job done in linear time, then we could solve this in O(n log k)

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int MOD = 1e9 + 7;

        // combine the vectors into one, why? you will see in a mnt
        vector<pair<int, int>> eng;

        for (int i = 0; i < n; i++){
            eng.push_back({efficiency[i], speed[i]});
        }

        // sort by efficiency
        sort(eng.begin(), eng.end(), greater<>());

        // priority queue
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long speedSum = 0, ans = 0;

        // turns out we need to know the speed of each engineer, and if we sorted the 
        // efficient list, we will lose tract of they speed and we wont know which engineer is which
        // so here we go

        for (auto &[e, s] : eng){
            minHeap.push(s);
            speedSum += s;

            if (minHeap.size() > k){
                speedSum -= minHeap.top();
                minHeap.pop();
            }

            ans = max(ans, speedSum * e);
        }

        return ans % MOD;
    }
};