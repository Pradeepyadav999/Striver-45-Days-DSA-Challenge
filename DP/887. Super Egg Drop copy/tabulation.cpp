#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        // Base cases
        for (int floors = 0; floors <= n; floors++)
            dp[1][floors] = floors;

        for (int eggs = 1; eggs <= k; eggs++) {
            dp[eggs][0] = 0;
            if (n >= 1)
                dp[eggs][1] = 1;
        }

        // Fill DP table
        for (int eggs = 2; eggs <= k; eggs++) {

            for (int floors = 2; floors <= n; floors++) {

                dp[eggs][floors] = INT_MAX;

                for (int x = 1; x <= floors; x++) {

                    int breakEgg = dp[eggs - 1][x - 1];

                    int surviveEgg = dp[eggs][floors - x];

                    dp[eggs][floors] = min(
                        dp[eggs][floors],
                        1 + max(breakEgg, surviveEgg)
                    );
                }
            }
        }

        return dp[k][n];
    }
};