#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() < 3) return -1;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        for (int num : nums) {
            if (num != mini && num != maxi)
                return num;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 2};
    int result = sol.findNonMinOrMax(nums);
    cout << "Result: " << result << endl; // Output: Result: 2
    return 0;
}