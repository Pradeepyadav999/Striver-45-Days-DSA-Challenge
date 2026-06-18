class Solution {
public:
    bool olve(vector<int>& nums, int index, int target){
        if(target==0) return true;
        if(index >= nums.size()){
            return false;
        }
        
        bool include = false;
        if(nums[index]<=target){
            include = solve(nums, index + 1,target - nums[index]);

        bool exclude = solve(nums, index + 1,target);

        return include || exclude;
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end());
        if(sum%2 != 0) return false;

        int target=sum/2;
        return solve(nums,0,target);
    }
};


// Time  : O(2^n)
// Space : O(n)