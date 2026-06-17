#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool solve(int currSum, int index, int target, vector<int>& arr) {
        // Found target
        if(currSum == target)
            return true;
        // Out of bounds
        if(index == arr.size())
            return false;
        // Optimization: all elements are positive
        if(currSum > target)
            return false;

        // Take current element
        if(solve(currSum + arr[index],index + 1,target,arr))
            return true;

        // Don't take current element
        if(solve(currSum,index + 1,target,arr))
            return true;

        return false;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        return solve(0, 0, target, arr);
    }
};

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;

    Solution obj;
    if(obj.isSubsetSum(arr, target))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}