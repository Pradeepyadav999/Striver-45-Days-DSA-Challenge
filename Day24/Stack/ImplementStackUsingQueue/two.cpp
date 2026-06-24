#include <iostream>
#include <queue>
using namespace std;    

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:

    void push(int x) {

        q2.push(x);

        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {

        if(q1.empty())
            return -1;

        int val = q1.front();
        q1.pop();

        return val;
    }

    int top() {

        if(q1.empty())
            return -1;

        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};


int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << obj->top() << endl; // Output: 2
    cout << obj->pop() << endl;  // Output: 2
    cout << obj->empty() << endl; // Output: 0 (false)
    return 0;
}