# include <string>
# include <vector>
# include<algorithm>
# include <queue>
using namespace std;

// Problem 38
// Problem 7 of Feb
// Reorganize String: MEDIUM
// Date: 11/02/26

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int n = s.size();
        int maxFreq = *max_element(freq.begin(), freq.end());
        if (maxFreq > (n + 1) / 2) return "";

        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push({freq[i], char('a' + i)});
        }

        string result = "";

        while (pq.size() >= 2) {
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();

            result.push_back(c1);
            result.push_back(c2);

            if (--f1 > 0) pq.push({f1, c1});
            if (--f2 > 0) pq.push({f2, c2});
        }

        // If one char remains
        if (!pq.empty()) {
            auto [f, c] = pq.top();
            if (f > 1) return ""; // safety, why? if more than one char (same) we can not add them to the res
            result.push_back(c);
        }

        return result;
    }
};
