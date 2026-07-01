#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int prevDiag = 0;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (s[i - 1] == rev[j - 1])
                    dp[j] = 1 + prevDiag;
                else
                    dp[j] = max(dp[j], dp[j - 1]);
                prevDiag = temp;
            }
        }
        return dp[n];
    }
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};

int main() {
    Solution sol;
    string s = "abcda";
    cout << sol.minInsertions(s) << endl; // Output: 2
    return 0;
}