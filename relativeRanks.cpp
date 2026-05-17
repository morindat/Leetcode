# include <queue>
# include <vector>
# include <string>
using namespace std;

// Problem 29
// Relative Rank: EASY
// Date: 28/01/26

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++){
            pq.push({score[i], i});
        }

        vector<string> res(n);
        int rank = 1;

        while (!pq.empty()){
            auto [score, ind] = pq.top(); 
            pq.pop();

            if (rank == 1) res[ind] = "Gold Medal";
            else if (rank == 2) res[ind] = "Silver Medal";
            else if (rank == 3) res[ind] = "Bronze Medal";
            else res[ind] = to_string(rank);

            rank++;
        }

        return res;
        
    }
};