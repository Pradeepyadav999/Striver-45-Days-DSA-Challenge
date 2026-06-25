// Using the array/vector
// Store stack element in array and sort vector and push back to stack
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    void sortStack(stack<int> &st) {
        vector<int> arr;
        while(!st.empty()) {
            arr.push_back(st.top());
            st.pop();
        }
        sort(arr.begin(), arr.end());
        for(int i = 0; i < (int)arr.size(); i++) {
            st.push(arr[i]);
        }    
    }
};

int main() {
    stack<int> st;
    st.push(34);
    st.push(3);
    st.push(31);
    st.push(98);
    st.push(92);
    st.push(23);

    Solution obj;
    obj.sortStack(st);

    cout << "Sorted numbers are:\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}