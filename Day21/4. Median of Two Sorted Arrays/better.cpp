#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                temp.push_back(nums1[i++]);
            }else{
                temp.push_back(nums2[j++]);
            }
        }
        while(i < nums1.size())
            temp.push_back(nums1[i++]);

        while(j < nums2.size())
            temp.push_back(nums2[j++]);
        int n = temp.size();
        if(n % 2 == 1) {
            return temp[n / 2];
        } else {
            return (temp[n/2 - 1] + temp[n/2]) / 2.0;
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