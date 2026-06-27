#include <algorithm>
#include <climits>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;
    MinStack() { 
    }
    
    void push(int value) {
        st.push(value);
    }
    
    void pop() {
        if (!st.empty())
            st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int>temp = st;
        int mini=INT_MAX;
        while(!temp.empty()){
            mini = min(mini,temp.top());
            temp.pop();
        }
        return mini;
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int param_3 = obj->getMin(); // Returns -3
    obj->pop();
    int param_4 = obj->top(); // Returns 0
    int param_5 = obj->getMin(); // Returns -2
    return 0;
}