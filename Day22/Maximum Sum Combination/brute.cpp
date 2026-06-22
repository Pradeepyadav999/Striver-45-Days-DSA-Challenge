#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> sums;
    int n= nums1.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sums.push_back(nums1[i]+nums2[j]);
        }
    }
    sort(sums.begin(), sums.end(), greater<int>());
    vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(sums[i]);
        }

    return ans;
  }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 4, 2, 3};
    vector<int> nums2 = {2, 5, 1, 6};
    int k = 4;
    vector<int> result = sol.maxSumCombinations(nums1, nums2, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}