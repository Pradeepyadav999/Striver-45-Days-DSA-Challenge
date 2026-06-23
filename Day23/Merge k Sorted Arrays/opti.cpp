#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        for(int i = 0; i < k; i++) {
            pq.push({arr[i][0], {i,0}});
        }

        vector<int> ans;

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int val = top.first;
            int row = top.second.first;
            int col = top.second.second;

            ans.push_back(val);

            if(col + 1 < arr[row].size()) {

                pq.push({
                    arr[row][col+1],
                    {row,col+1}
                });
            }
        }

        return ans;
    }
};

int main() {
    Solution* obj = new Solution();
    vector<vector<int>> mat = {{1,3,5},{2,6,9},{3,6,9}};
    vector<int> ans = obj->mergeKSortedArrays(mat, mat.size());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}