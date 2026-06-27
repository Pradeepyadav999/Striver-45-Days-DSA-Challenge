#include <iostream>
#include <vector>
using namespace std;    

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        for (int i = 0; i <= nums.size() - k; i++) {
            int maxVal = nums[i];
            for (int j = i; j < i + k; j++) {
                maxVal = max(maxVal, nums[j]);
            }
            result.push_back(maxVal);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = solution.maxSlidingWindow(nums, k);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}