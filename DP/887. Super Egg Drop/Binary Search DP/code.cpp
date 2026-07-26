#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int solve(int eggs, int floors, vector<vector<int>>& dp) {

        if (floors == 0 || floors == 1)
            return floors;

        if (eggs == 1)
            return floors;

        if (dp[eggs][floors] != -1)
            return dp[eggs][floors];

        int low = 1;
        int high = floors;

        int ans = INT_MAX;

        while (low <= high) {

            int mid = (low + high) / 2;

            int breakEgg = solve(eggs - 1, mid - 1, dp);

            int surviveEgg = solve(eggs, floors - mid, dp);

            int moves = 1 + max(breakEgg, surviveEgg);

            ans = min(ans, moves);

            if (breakEgg < surviveEgg)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return dp[eggs][floors] = ans;
    }

    int superEggDrop(int k, int n) {

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));

        return solve(k, n, dp);
    }
};