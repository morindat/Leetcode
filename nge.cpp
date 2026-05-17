#include <vector>
#include <stack>
# include <unordered_map>
using namespace std;

// Problem 48
// Problem 18 of Feb
// NGE: EASY
// Date: 22/02/26
// I could not solve trapping rain water 2
// so i was like fuck it lets do an easier problem

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // map to store all the elements with they nge
        // monotonic stack to keep determine nge

        unordered_map<int, int> nge;
        stack<int> st;

        for (int num : nums2){
            // if st is not empty
            // and the number we are looking at is greater than 
            // that in stack
            // means we found the greater number for that element in stack
            // so add it to the nge map
            while (!st.empty() && num > st.top()){
                nge[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // fill the rest with all 0s
        while (!st.empty()){
            nge[st.top()] = -1;
            st.pop();
        }

        // now look into the map and find the nge for every element
        vector<int> res;

        for (int num: nums1){
            res.push_back(nge[num]);
        }

        return res;
    }
};