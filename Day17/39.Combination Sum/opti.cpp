class Solution {
public:
    void solve(vector<int>& candidates,int idx,int target,vector<vector<int>>&ans,vector<int>&combin){
        if(target==0){
            ans.push_back(combin);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            combin.push_back(candidates[i]);
            solve(candidates,i+1,target-candidates[i],ans,combin);
            combin.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>combin;
        solve(candidates,0,target,ans,combin);
        return ans;
    }
};