// Problem : 416. Partition Equal Subset Sum solve using Memoization

// Time  : O(n × target)
// Space : O(n × target)

class Solution {
public:
    bool solve(vector<int>& nums, int index, int target, vector<vector<int>>& dp){
        if(target==0) return true;

        if(index >= nums.size()){
            return false;
        }

        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        bool include = false;

        if(nums[index]<=target){
            include = solve(nums, index + 1,target - nums[index],dp);
        }
        bool exclude = solve(nums, index + 1,target,dp);

        return dp[index][target] = include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 != 0) return false;
        int target=sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target + 1, -1));
        return solve(nums,0,target,dp);
    }
};
