#include<iostream>
#include<queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> left;   
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
    }

    void addNum(int num) {
        if (left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size())
            return (left.top() + right.top()) / 2.0;
        if (left.size() > right.size())
            return left.top();

        return right.top();
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; 
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; 
    return 0;
}