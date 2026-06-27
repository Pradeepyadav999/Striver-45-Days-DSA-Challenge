#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int nextSmaller = -1;
            for(int j=i+1;j<n;j++){
                if (arr[j] < arr[i]) {
                    nextSmaller = arr[j];
                    break;
                }
            }
            ans.push_back(nextSmaller);
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = obj.nextSmallerEle(arr);

    cout << "Next smaller elements are:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}