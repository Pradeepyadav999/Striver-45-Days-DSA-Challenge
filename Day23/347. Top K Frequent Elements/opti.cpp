// Min Heap of Size K (Optimal Heap)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        for(int num : nums)
            mp[num]++;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for(auto p : mp)
        {
            pq.push({p.second,p.first});

            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

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