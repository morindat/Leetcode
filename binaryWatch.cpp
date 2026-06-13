#include <vector>
#include <string>
#include <bitset>
using namespace std;

/**
 * Problem 181
 * Problem 18/45 of June 2026
 * Binary Watch: EASY
 * Date: 13/06/26
 * Time Complexity: O(1) per querry
*/

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        static vector<vector<string>> cache = []() {
            vector<vector<string>> cache(11);

            for (int h = 0; h < 12; h++) {
                for (int m = 0; m < 60; m++) {
                    int bits = __builtin_popcount(h) + __builtin_popcount(m);
                    string time = to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
                    cache[bits].push_back(time);
                }
            }

            return cache;
        }();

        return cache[turnedOn];
    }
};