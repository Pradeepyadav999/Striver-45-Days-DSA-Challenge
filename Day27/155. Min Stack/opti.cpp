#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
    }
    void push(int value) {
        if (st.empty()) {
            st.push(value);
            mini = value;
        }
        else if (value >= mini) {
            st.push(value);
        }
        else {

            st.push(2LL * value - mini);
            mini = value;
        }
    }
    void pop() {
        if (st.empty())
            return;
        if (st.top() < mini) {
            mini = 2LL * mini - st.top();
        }
        st.pop();
    }
    int top() {
        if (st.top() >= mini)
            return st.top();
        return mini;
    }
    int getMin() {
        return mini;
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl; // return -3
    obj->pop();
    cout << obj->top() << endl;    // return 0
    cout << obj->getMin() << endl; // return -2
}