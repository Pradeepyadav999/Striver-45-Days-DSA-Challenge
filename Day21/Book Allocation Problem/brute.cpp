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
        for(int pageAllowed=low;pageAllowed<=high;pageAllowed++){
            if(possible(pageAllowed,nums,m)){
                return pageAllowed;
            }
        }
        return -1;
    }
};