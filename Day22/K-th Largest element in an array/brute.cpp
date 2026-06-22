#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << sol.findKthLargest(nums, k) << endl; // Output: 5
    return 0;
}

// TC= O(n log n)
// SC= O(1)