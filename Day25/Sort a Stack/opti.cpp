#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:

    void insertSorted(stack<int>& st, int x) {

        if(st.empty() || st.top() <= x) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertSorted(st, x);

        st.push(temp);
    }

    void sortStack(stack<int>& st) {

        if(st.size() == 1)
            return;

        int top = st.top();
        st.pop();

        sortStack(st);

        insertSorted(st, top);
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