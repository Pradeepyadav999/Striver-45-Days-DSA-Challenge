#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int i, vector<vector<int>>& jobs) {

        // Base case
        if (i >= jobs.size())
            return 0;

        // Find the next non-overlapping job
        int next = i + 1;
        while (next < jobs.size() && jobs[next][0] < jobs[i][1]) {
            next++;
        }

        // Take current job
        int take = jobs[i][2] + solve(next, jobs);

        // Skip current job
        int notTake = solve(i + 1, jobs);

        return max(take, notTake);
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
        return solve(0, jobs);
    }
};