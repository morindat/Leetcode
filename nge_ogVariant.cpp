# include <stack>
# include <vector>
# include <iostream>
using namespace std;

vector<int> nge(vector<int>& nums){
    int n = nums.size();
    stack<int> st;
    vector<int> res(n, -1);

    for (int i = 0; i < n; i++){
        while (!st.empty() && nums[i] > nums[st.top()]){
            res[st.top()] = nums[i];
            st.pop();
        }

        st.push(i);
    }

    return res;
}

int main(){
    vector<int> nums = {2, 3, 4, 5};

    vector<int> res = nge(nums);

    for (int num : res){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}