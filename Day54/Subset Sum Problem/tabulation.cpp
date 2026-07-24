#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base Case 1: Target = 0 is always possible
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Base Case 2: Using only the first element
        if (arr[0] <= sum)
            dp[0][arr[0]] = true;

        // Fill the DP table
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= sum; target++) {

                bool notTake = dp[ind - 1][target];

                bool take = false;
                if (arr[ind] <= target)
                    take = dp[ind - 1][target - arr[ind]];

                dp[ind][target] = take || notTake;
            }
        }

        return dp[n - 1][sum];
    }
};