// Max Heap
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int num : nums)
            pq.push(num);

        for(int i = 1; i < k; i++)
            pq.pop();

        return pq.top();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << sol.findKthLargest(nums, k) << endl; // Output: 5
    return 0;
}
// Build Heap : O(n)
// Pop k-1    : O(k log n)

// Total      : O(n + k log n)
// Space      : O(n)