#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        vector<double> ans;
        for(int i=0;i<=n-k;i++){
            vector<int> window;
            for(int j=i;j<i+k;j++){
                window.push_back(nums[j]);
            }
            sort(window.begin(), window.end());
            if(k % 2 == 1) {
                ans.push_back(window[k / 2]);
            }
            else {
                double median =((double)window[k/2 - 1] +(double)window[k/2]) / 2.0;
                ans.push_back(median);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<double> result = solution.medianSlidingWindow(nums, k);
    
    for (double median : result) {
        cout << median << " ";
    }
    
    return 0;
}