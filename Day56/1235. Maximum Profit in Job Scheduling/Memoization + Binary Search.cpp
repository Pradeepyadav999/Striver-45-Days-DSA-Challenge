#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int i, vector<vector<int>>& jobs, vector<int>& dp) {

        if (i >= jobs.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Binary Search to find the next non-overlapping job
        int next = lower_bound(
            jobs.begin(),
            jobs.end(),
            jobs[i][1],
            [](const vector<int>& job, int endTime) {
                return job[0] < endTime;
            }
        ) - jobs.begin();

        int take = jobs[i][2] + solve(next, jobs, dp);

        int notTake = solve(i + 1, jobs, dp);

        return dp[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n, -1);

        return solve(0, jobs, dp);
    }
};