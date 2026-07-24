#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins){
        if(ind==0){
            if (amount % coins[0] == 0)
                return 1;
            return 0;
        }
        int notTake = solve(ind-1,amount,coins);
        int take=0;
        if(coins[ind]<=amount){
            take = solve(ind, amount - coins[ind], coins);
        }
        return take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        return solve(n-1,amount,coins);
    }
};