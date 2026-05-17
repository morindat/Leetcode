# include <vector>
# include<algorithm>
# include <queue>
using namespace std;

// Problem 38
// Problem 8 of Feb
// Minimum Cost To Hire K Workers: HARD
// Date: 12/02/26

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> workers;

        for(int i = 0; i < n; i++){
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        // sort by ratio
        sort(workers.begin(), workers.end());

        priority_queue<int> maxHeap; // stores qualities
        int sumQ = 0;
        double ans = 1e18;

        for(auto& w : workers){
            double r = w.first;
            int q = w.second;

            maxHeap.push(q);
            sumQ += q;

            if(maxHeap.size() > k){
                sumQ -= maxHeap.top();
                maxHeap.pop();
            }

            if(maxHeap.size() == k){
                ans = min(ans, r * sumQ);
            }
        }

        return ans;
    }
};
