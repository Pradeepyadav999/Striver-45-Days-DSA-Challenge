// Its from Front code 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int idx1, int idx2, string &text1, string &text2, vector<vector<int>> &dp) {
        // Base case
        if (idx1 == text1.size() || idx2 == text2.size())
            return 0;

        // Already computed
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        // Characters match
        if (text1[idx1] == text2[idx2]) {
            return dp[idx1][idx2] =
                1 + solve(idx1 + 1, idx2 + 1, text1, text2, dp);
        }

        // Characters don't match
        return dp[idx1][idx2] = max(
            solve(idx1 + 1, idx2, text1, text2, dp),
            solve(idx1, idx2 + 1, text1, text2, dp)
        );
    }
    int longestPalindromeSubseq(string s) {
        string sReve = s;
        reverse(sReve.begin(), sReve.end());   
        int n = s.size();
        int m = sReve.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));     
        return solve(0, 0, s, sReve,dp);
    }
};

int main() {
    Solution sol;
    string s = "bbbab";
    int result = sol.longestPalindromeSubseq(s);
    cout << "Length of longest palindromic subsequence: " << result << endl;
    return 0;
}