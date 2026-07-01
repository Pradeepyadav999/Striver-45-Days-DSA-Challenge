#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int ans=0;
    bool isPalindrome(string str){
        int left = 0;
        int right = str.size() - 1;

        while (left < right) {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }    
        return true;
    }
    void generate(int index, string &s, string curr) {
        if (index == s.size()) {
            if (isPalindrome(curr))
                ans = max(ans, (int)curr.size());
            return;
        }
        generate(index + 1, s, curr + s[index]);
        generate(index + 1, s, curr);
    }
    int longestPalindromeSubseq(string s) {
        generate(0, s, "");
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "bbbab";
    int result = sol.longestPalindromeSubseq(s);
    cout << "Length of longest palindromic subsequence: " << result << endl;
    return 0;
}
