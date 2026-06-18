class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        // Base Cases
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        if(dp[amount]!=-1){
            return dp[amount];
        }
        
        int mini = INT_MAX;     //Maximum number of coins needed can be amount (if all coins are 1)

        for (int coin : coins) {
            // recAns returns the minimum number of coins needed for the remaining amount
            int recAns = solve(coins, amount - coin, dp);

            if (recAns != INT_MAX) {
                mini = min(mini, 1 + recAns); // 1 for the current coin + recAns for the remaining amount
            }
        }
        return dp[amount] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        // Create Dp array to store coins needed for each amount from 0 to amount
        vector<int> dp(amount+1,-1);
        int ans = solve(coins, amount, dp);

        return (ans == INT_MAX) ? -1 : ans;
    }
};