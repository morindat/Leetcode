# include <vector>
# include <algorithm>
# include <climits>
# include <iostream>

using namespace std;

// Problem No. 2
// Heaters: MEDIUM
// Date: 02/01/26
// One of the stupiest problem statements in LeetCode, no cap!

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int ans = 0;
        int j = 0;

        for (int house : houses){
            // Only move the heater's pointer when the next one is closer that the current one
            while(j + 1 < heaters.size() && abs(heaters[j + 1] - house) <= abs(heaters[j] - house)){
                j++;
            }
            ans = max(ans, abs(heaters[j] - house));
        }
        return ans;
    }
};


int main(){

    Solution sol;

    vector<int> houses = {1, 2, 4, 10};
    vector<int> heaters = {2, 3};

    int res = sol.findRadius(houses, heaters);
    cout << "Radius: " << res << endl;

    return 0;
}