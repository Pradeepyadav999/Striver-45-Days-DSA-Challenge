#include <iostream>
using namespace std;

class ArrayStack {
private:
    int topIdx;
    int array[100];

public:
    ArrayStack() {
        topIdx = -1;
    }
    
    void push(int x) {
        topIdx=topIdx+1;
        array[topIdx]=x;
    }
    int pop() {
        if(topIdx == -1)
            return -1;
        int poppedElement = array[topIdx];
        topIdx--;
        return poppedElement;
    }
    
    int top() {
        return array[topIdx];
    }
    
    bool isEmpty() {
        return topIdx == -1;
    }
};

int main() {
    ArrayStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << "Top element: " << stack.top() << endl; // Output: 30
    cout << "Popped element: " << stack.pop() << endl; // Output: 30
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: No
    
    return 0;
}