#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq;

        for(int num : nums) {

            pq.push(num);

            if(pq.size() > k)
                pq.pop();
        }

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