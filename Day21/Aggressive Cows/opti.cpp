
class Solution {
public:
    bool cowPlace(int distance, vector<int> &nums, int k) {
        int count = 1;          
        int lastPos = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - lastPos >= distance) {
                count++;
                lastPos = nums[i];
            }
            if(count >= k)
                return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low=1;
        int high=nums[n - 1] - nums[0];
        int ans=0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(cowPlace(mid, nums, k)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};