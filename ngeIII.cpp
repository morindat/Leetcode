# include <string>
# include <algorithm>
using namespace std;

// Problem 52
// Problem 22 of Feb
// NGE III: MEDIUM
// Date: 25/02/26

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.length();

        // find the dip
        // we need where the elements start reducing
        // that is element at i is less than that at i + 1
        int i = len - 2;

        while (i >= 0 && s[i] >= s[i + 1]){
            i--;
        }

        // so now we are pointing at some index i where
        // the element right next to i is greater than i
        // suppose we are at some < 0 index
        // means we are unlucky so return -

        if (i < 0) return -1;

        // otherwise
        // we need to find some element at index i
        // such that, that element is smaller than
        // every other elements to the right
        // but greater than the element at i
        int j = len - 1;
        while (s[j] <= s[i]){
            j--;
        }

        // 3️⃣ Swap
        swap(s[i], s[j]);

        // now we need to do one more thing
        // reverse the suffix
        reverse(s.begin() + i + 1, s.end());

        // check if anw fits in 32 bits register
        long long ans = stoll(s);
        if (ans > INT_MAX) return -1;

        return (int)ans;
    }
};