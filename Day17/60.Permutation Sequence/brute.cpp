class Solution {
public:

    void solve(vector<int>& nums,vector<bool>& used,string& ds,vector<string>& ans) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(used[i])
                continue;
            used[i] = true;
            ds += to_string(nums[i]);
            solve(nums, used, ds, ans);
            ds.pop_back();
            used[i] = false;
        }
    }
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; i++)
            nums.push_back(i);
        vector<string> ans;
        vector<bool> used(n, false);
        string ds = "";
        solve(nums, used, ds, ans);
        return ans[k - 1];
    }
};