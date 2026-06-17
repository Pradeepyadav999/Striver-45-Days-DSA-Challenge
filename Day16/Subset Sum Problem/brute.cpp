#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool solve(int s, int indx, int sum, vector<int>& arr){
        if(s > sum)
            return false;
        
        if(indx==arr.size()){
            return s==sum;
        }
        //Take sum
        if(solve(s+arr[indx], indx+1, sum, arr))
            return true;
        //Not take    
        if(solve(s,indx+1,sum,arr))
            return true;
        
        return false;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        return solve(0,0,sum,arr);
    }
};

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    Solution obj;
    if(obj.isSubsetSum(arr, sum))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}