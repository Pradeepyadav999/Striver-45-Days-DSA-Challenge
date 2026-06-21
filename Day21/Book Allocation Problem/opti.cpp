class Solution {
public:
    bool possible(int pageAllowed, vector<int> &nums, int m)   {
        int students=1;
        int page=0;
        for(int book : nums){
            if(page+book<=pageAllowed){
                page+=book;
            }else{
                students+=1;
                page=book;
            }
        }
        return students<=m;
    }
    int findPages(vector<int> &nums, int m)  {
        int n=nums.size();
        if(m>n) return -1;        

        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(possible(mid,nums,m)){
                ans = mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};