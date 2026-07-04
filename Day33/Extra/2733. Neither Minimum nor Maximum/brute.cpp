#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()<=2) return -1;
        sort(nums.begin(),nums.end());
        return nums[1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 2};
    int result = sol.findNonMinOrMax(nums);
    cout << "Result: " << result << endl; // Output: Result: 2
    return 0;
}