#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int low = 0, high = nums.size() - 1;

        while (low <= high) {

            int pivotIndex = low + rand() % (high - low + 1);
            int pivot = nums[pivotIndex];

            int lt = low, i = low, gt = high;

            while (i <= gt) {
                if (nums[i] < pivot) {
                    swap(nums[lt++], nums[i++]);
                } else if (nums[i] > pivot) {
                    swap(nums[i], nums[gt--]);
                } else {
                    i++;
                }
            }

            if (target < lt) {
                high = lt - 1;
            } else if (target > gt) {
                low = gt + 1;
            } else {
                return nums[target];
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = sol.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;
    return 0;
}