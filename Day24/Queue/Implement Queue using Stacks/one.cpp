#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> st;

public:

    void push(int x) {
        st.push(x);
    }

    int pop() {

        int x = st.top();
        st.pop();

        if(st.empty())
            return x;

        int res = pop();

        st.push(x);

        return res;
    }

    int peek() {

        int x = st.top();
        st.pop();

        if(st.empty()) {
            st.push(x);
            return x;
        }

        int res = peek();

        st.push(x);

        return res;
    }

    bool empty() {
        return st.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl; // returns 1
    cout << q.pop() << endl;  // returns 1
    cout << q.empty() << endl; // returns false
    return 0;
}   