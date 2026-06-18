class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& path, vector<bool>& used){
        // base Case
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        // choices
        for(int i=0;i<nums.size();i++){
            if (used[i]){
                continue;
            }
            // choose
            path.push_back(nums[i]);
            used[i]=true;
            // Recurse
            solve(nums,path,used);
            // Backtrack
            path.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>path;
        vector<bool>used(nums.size(),false);
        solve(nums,path,used);
        return ans;
    }
};