#include <vector>
using namespace std;

// Problem 56
// Problem 2 of March
// Find The Town Judge: EASY
// Date: 04/03/26

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // store the relationships as a count of 
        // in and out degrees
        // the judge, is trusted by everyone (n - 1 people)
        // trusts no one (0 people)
        // one being only
        if (n == 1) return 1;

        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        for (auto& t : trust){
            int a = t[0];
            int b = t[1];

            outdegree[a]++; // (a trusts b)
            indegree[b]++; // (b is trusted by a)
        }

        // seach for this man/woman/whatever
        for (int i = 0; i <= n; i++){
            if (indegree[i] == n - 1 && outdegree[i] == 0){
                return i;
            }
        }

        return -1;
    }
};
