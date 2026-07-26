#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int eggs, int floors, vector<vector<int>>& dp){
        // Base case
        if(floors == 0 || floors == 1) return floors;        
        if(eggs==1) return floors;      // if one egg return floor

        if (dp[eggs][floors] != -1)
            return dp[eggs][floors];

        int ans = INT_MAX;
        // try every floors
        for(int x=1;x<=floors;x++){
            int breakEgg = solve(eggs-1, x-1,dp);
            int surviveEgg = solve(eggs, floors-x, dp);
            int moves = 1 + max(breakEgg, surviveEgg);
            ans = min(ans, moves);
        }
        return dp[eggs][floors] = ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};