#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> mergeTwoArrays(vector<int>& a,vector<int>& b){
        vector<int>ans;
        int i = 0;
        int j = 0;
         while(i < a.size() && j < b.size()) {

            if(a[i] <= b[j]) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i < a.size()) {
            ans.push_back(a[i]);
            i++;
        }

        while(j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        if(mat.empty()) return {};
        
        vector<int> result = mat[0];
        for(int i=1;i<mat.size();i++){
            result =mergeTwoArrays(result,mat[i]); 
        }
        return result;
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