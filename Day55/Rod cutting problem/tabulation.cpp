#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int cutRod(vector<int> &price) {
        int n = price.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Base case
        for(int len = 0; len <= n; len++){
            dp[0][len] = price[0] * len;
        }

        // Fill DP table
        for(int idx = 1; idx < n; idx++){
            int rodLen = idx + 1;

            for(int remLen = 0; remLen <= n; remLen++){

                int notTake = dp[idx - 1][remLen];

                int take = INT_MIN;
                if(rodLen <= remLen){
                    take = price[idx] + dp[idx][remLen - rodLen];
                }

                dp[idx][remLen] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
};