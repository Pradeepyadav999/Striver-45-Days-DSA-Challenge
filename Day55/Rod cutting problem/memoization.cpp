#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int solve(int idx, vector<int> price, int remLen,vector<vector<int>>&dp){
        if(idx==0){
            return price[0]*remLen;
        }
        
        if(dp[idx][remLen] != -1)
            return dp[idx][remLen];

        int notTake = solve(idx-1,price,remLen,dp);
        int take=INT_MIN;
        int rodLen=idx+1;
        if(rodLen<=remLen){
            take=price[idx]+solve(idx,price,remLen-rodLen,dp);
        }
        return dp[idx][remLen] = max(take, notTake);
    }
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n-1,price,n,dp);
    }
};
