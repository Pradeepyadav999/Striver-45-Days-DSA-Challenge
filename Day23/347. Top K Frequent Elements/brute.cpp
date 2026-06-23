#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        for(int num : nums)
            mp[num]++;

        vector<pair<int,int>> freq;

        for(auto p : mp)
            freq.push_back({p.first,p.second});

        sort(freq.begin(), freq.end(),[](auto &a, auto &b){
            return a.second > b.second;
        });

        vector<int> ans;

        for(int i=0;i<k;i++)
            ans.push_back(freq[i].first);

        return ans;
    }
};



int main()
{
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements: ";
    for(int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}