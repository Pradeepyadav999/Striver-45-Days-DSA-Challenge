#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int eggs, int floors){
        // Base case
        if(floors == 0 || floors == 1) return floors;        
        if(eggs==1) return floors;      // if one egg return floor

        int ans = INT_MAX;
        // try every floors
        for(int x=1;x<=floors;x++){
            int breakEgg = solve(eggs-1, x-1);
            int surviveEgg = solve(eggs, floors-x);
            int moves = 1 + max(breakEgg, surviveEgg);
            ans = min(ans, moves);
        }
        return ans;
    }
    int superEggDrop(int k, int n) {
        return solve(k,n);
    }
};