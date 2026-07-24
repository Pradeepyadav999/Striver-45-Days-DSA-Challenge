#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {

        if (target == 0)
            return true;

        if (ind == 0)
            return arr[0] == target;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTake = solve(ind - 1, target, arr, dp);

        bool take = false;
        if (arr[ind] <= target)
            take = solve(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = take || notTake;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return solve(n - 1, sum, arr, dp);
    }
};