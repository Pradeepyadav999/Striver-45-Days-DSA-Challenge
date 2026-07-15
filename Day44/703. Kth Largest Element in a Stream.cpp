#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
    }
    int add(int val) {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    cout << kthLargest.add(3) << endl;  
    cout << kthLargest.add(5) << endl;  
    cout << kthLargest.add(10) << endl; 
    cout << kthLargest.add(9) << endl;  
    cout << kthLargest.add(4) << endl;  
    return 0;
}