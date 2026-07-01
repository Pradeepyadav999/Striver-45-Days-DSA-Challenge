#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int idx1,int idx2,string text1, string text2, vector<vector<int>> &dp){
        // Base Case
        if(idx1<0 || idx2<0){
            return 0;
        }

        // already computed
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }

        // If character match
        if(text1[idx1]==text2[idx2]){
            return dp[idx1][idx2] = 1+solve(idx1-1,idx2-1,text1,text2,dp);
        }

        // Character don`t match
        return dp[idx1][idx2] = max(solve(idx1-1,idx2,text1,text2,dp),solve(idx1,idx2-1,text1,text2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1.size() - 1, text2.size() - 1, text1, text2, dp);
    }
};

int main(){
    Solution s;
    string text1 = "abcde";
    string text2 = "ace"; 
    cout<<s.longestCommonSubsequence(text1,text2);
}