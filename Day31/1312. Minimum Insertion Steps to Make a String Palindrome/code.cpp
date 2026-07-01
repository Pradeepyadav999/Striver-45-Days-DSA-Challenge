// THis code is same as the longest palindromic subsequence which is day 32 extra questions
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // Base cases
        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        // LCS Tabulation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == rev[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};

int main() {
    Solution sol;
    string s = "abcda";
    cout << "Minimum insertions to make the string a palindrome: " << sol.minInsertions(s) << endl;
    return 0;
}