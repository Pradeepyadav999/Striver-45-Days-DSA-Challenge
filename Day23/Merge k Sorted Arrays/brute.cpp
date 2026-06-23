#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        int r=mat.size();
        int c=mat[0].size();
        vector<int>ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans.push_back(mat[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution* obj = new Solution();
    vector<vector<int>> mat = {{1,3,5},{2,6,9},{3,6,9}};
    vector<int> ans = obj->mergeArrays(mat);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
 }