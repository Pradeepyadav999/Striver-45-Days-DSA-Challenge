class Solution {
public:

    void solve(vector<int>& nums,
               vector<int>& ds,
               vector<vector<int>>& ans,
               vector<bool>& used) {

        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(used[i])
                continue;

            used[i] = true;

            ds.push_back(nums[i]);

            solve(nums, ds, ans, used);

            ds.pop_back();

            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> used(nums.size(), false);

        solve(nums, ds, ans, used);

        return ans;
    }
};