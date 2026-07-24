#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool solve(int ind, int target, vector<int>& arr) {

        if (target == 0)
            return true;

        if (ind == 0)
            return arr[0] == target;

        bool notTake = solve(ind - 1, target, arr);

        bool take = false;
        if (arr[ind] <= target)
            take = solve(ind - 1, target - arr[ind], arr);

        return take || notTake;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        return solve(n - 1, sum, arr);
    }
};