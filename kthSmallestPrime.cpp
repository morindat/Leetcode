#include <vector>
#include <queue>
using namespace std;

// Problem 46
// Problem 16 of Feb
// K-th Smallest Prime Fraction: MEDIUM
// Date: 20/02/26

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        // min heap: (value, i, j)
        // a comparator function
        auto cmp = [&](tuple<double,int,int>& a,
                       tuple<double,int,int>& b) {
            return get<0>(a) > get<0>(b);
        };

        priority_queue<
            tuple<double,int,int>,
            vector<tuple<double,int,int>>,
            decltype(cmp)
        > minHeap(cmp);

        // push smallest fraction for each numerator
        for (int i = 0; i < n - 1; i++) {
            minHeap.push({(double)arr[i] / arr[n-1], i, n-1});
        }

        while (--k) {
            auto [val, i, j] = minHeap.top();
            minHeap.pop();

            // while j != i, keep pushing
            if (j - 1 > i) {
                minHeap.push({(double)arr[i] / arr[j-1], i, j-1});
            }
        }

        auto [val, i, j] = minHeap.top();
        return {arr[i], arr[j]};
    }
};