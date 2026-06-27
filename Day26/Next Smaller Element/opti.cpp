#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = obj.nextSmallerEle(arr);

    cout << "Next smaller elements are:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}