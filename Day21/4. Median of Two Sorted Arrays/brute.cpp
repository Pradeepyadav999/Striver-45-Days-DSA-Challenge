#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> temp;
        for(int num : nums1)
            temp.push_back(num);
        for(int num : nums2)
            temp.push_back(num);
        sort(temp.begin(), temp.end());
        int size = temp.size();
        int mid = size / 2;
        if(size % 2 == 0) {
            return (temp[mid - 1] + temp[mid]) / 2.0;
        } else {
            return temp[mid];
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double result = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << result << endl; // Output: Median: 2
    return 0;
}