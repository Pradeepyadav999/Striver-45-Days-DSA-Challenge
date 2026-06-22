#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int partition(vector<int>& nums, int low, int high) {

        int pivot = nums[high];
        int i = low;

        for(int j = low; j < high; j++) {

            if(nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[high]);

        return i;
    }

    int quickSelect(vector<int>& nums,
                    int low,
                    int high,
                    int k) {

        int pivotIndex = partition(nums, low, high);

        if(pivotIndex == k)
            return nums[pivotIndex];

        if(pivotIndex < k)
            return quickSelect(nums,
                              pivotIndex + 1,
                              high,
                              k);

        return quickSelect(nums,
                          low,
                          pivotIndex - 1,
                          k);
    }

    int findKthLargest(vector<int>& nums, int k) {

        int target = nums.size() - k;

        return quickSelect(
            nums,
            0,
            nums.size() - 1,
            target
        );
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << sol.findKthLargest(nums, k) << endl; // Output: 5
    return 0;
}