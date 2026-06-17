// Use pick and not pick to generate all possible sub sets
// Put all the subset in set avois duplicates
// Convert this set in list of list and return
 
class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& ds, set<vector<int>>& st){
        if(index==nums.size()){
            st.insert(ds);
            return;
        }
        // Take
        ds.push_back(nums[index]);
        solve(index + 1, nums, ds, st);

        // Not take
        ds.pop_back();
        solve(index + 1, nums, ds, st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {       
        set<vector<int>> st;
        vector<int>ds;
        solve(0, nums, ds, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};