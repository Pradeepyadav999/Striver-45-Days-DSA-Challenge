#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int i,
              vector<int>& startTime,
              vector<int>& endTime,
              vector<int>& profit,
              vector<int>& dp) {

        if (i >= startTime.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Find first job whose startTime >= current endTime
        int next = lower_bound(startTime.begin(),
                               startTime.end(),
                               endTime[i]) - startTime.begin();

        int take = profit[i] + solve(next, startTime, endTime, profit, dp);

        int notTake = solve(i + 1, startTime, endTime, profit, dp);

        return dp[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        vector<tuple<int,int,int>> jobs;

        for (int i = 0; i < n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end());

        for (int i = 0; i < n; i++) {
            startTime[i] = get<0>(jobs[i]);
            endTime[i]   = get<1>(jobs[i]);
            profit[i]    = get<2>(jobs[i]);
        }

        vector<int> dp(n, -1);

        return solve(0, startTime, endTime, profit, dp);
    }
};