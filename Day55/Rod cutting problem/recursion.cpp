#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int solve(int idx, vector<int> price, int remLen){
        // Base case
        if(idx==0){
            return price[0]*remLen;
        }
        // Not Take
        int notTake = solve(idx-1,price,remLen);
        int take=INT_MIN;
        int rodLen=idx+1;
        if(rodLen<=remLen){
            take=price[idx]+solve(idx,price,remLen-rodLen);
        }
        return max(take,notTake);
    }
    int rodCutting(vector<int> price, int n) {
        // we use n-1 because the array is zero based indexing
        return solve(n-1,price,n);
    }
};
