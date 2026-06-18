class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        // Base Cases
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        int mini = INT_MAX;     //Maximum number of coins needed can be amount (if all coins are 1)

        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i];
            // recAns returns the minimum number of coins needed for the remaining amount
            int recAns = solve(coins, amount - coin);

            if (recAns != INT_MAX) {
                int coinUsed = 1 + recAns;
                mini = min(mini, coinUsed);
            }
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);

        return (ans == INT_MAX) ? -1 : ans;
    }
};