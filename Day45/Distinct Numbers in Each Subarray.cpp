#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }

        ans.push_back(freq.size());

        for (int i = k; i < nums.size(); i++) {

            freq[nums[i - k]]--;

            if (freq[nums[i - k]] == 0)
                freq.erase(nums[i - k]);

            freq[nums[i]]++;

            ans.push_back(freq.size());
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    vector<int> result = sol.distinctNumbers(nums, k);
    
    cout << "Distinct numbers in each subarray of size " << k << ": ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}