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
        int maxDist = nums[n - 1] - nums[0];
        int ans = 0;
        for(int dist = 1; dist <= maxDist; dist++) {
            if(cowPlace(dist, nums, k))
                ans = dist;
        }
        return ans;
    }
};