#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>> jobs;

        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n+1,0);

        // Fill DP from right to left
        for(int i=n-1;i>=0;i--){

            // Find next non-overlapping job
            int next = i+1;

            while(next<n && jobs[next][0] < jobs[i][1]){
                next++;
            }

            int take = jobs[i][2] + dp[next];

            int notTake = dp[i+1];

            dp[i] = max(take, notTake);
        }

        return dp[0];
    }
};