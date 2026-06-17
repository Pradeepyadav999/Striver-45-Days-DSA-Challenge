class Solution {
public:
    set<vector<int>>s;
    void getCombination(vector<int>& candidates, int idx, int target, vector<vector<int>>& ans, vector<int>& combin){
        if(target == 0){
            if(s.find(combin)==s.end()){
                ans.push_back(combin);
                s.insert(combin);
                return;
            }
        }
        if(idx==candidates.size() || target<0){
            return;
        }
        combin.push_back(candidates[idx]);
        // Single include
        getCombination(candidates,idx+1,target-candidates[idx],ans,combin);
        // Multiple include
        getCombination(candidates,idx,target-candidates[idx],ans,combin);
        // For exclusion we have to pop back push value for the exclusion Backtracking
        combin.pop_back();
        // Exclude
        getCombination(candidates,idx+1,target,ans,combin);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>combin;
        getCombination(candidates,0,target,ans,combin);
        return ans;
    }
};class Solution {
public:
    set<vector<int>>s;
    void getCombination(vector<int>& candidates, int idx, int target, vector<vector<int>>& ans, vector<int>& combin){
        if(target == 0){
            if(s.find(combin)==s.end()){
                ans.push_back(combin);
                s.insert(combin);
                return;
            }
        }
        if(idx==candidates.size() || target<0){
            return;
        }
        combin.push_back(candidates[idx]);
        // Single include
        getCombination(candidates,idx+1,target-candidates[idx],ans,combin);
        // Multiple include
        getCombination(candidates,idx,target-candidates[idx],ans,combin);
        // For exclusion we have to pop back push value for the exclusion Backtracking
        combin.pop_back();
        // Exclude
        getCombination(candidates,idx+1,target,ans,combin);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>combin;
        getCombination(candidates,0,target,ans,combin);
        return ans;
    }
};