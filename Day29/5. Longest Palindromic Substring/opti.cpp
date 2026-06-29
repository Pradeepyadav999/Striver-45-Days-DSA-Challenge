#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    int start = 0;
    int maxLen = 1;

    void expand(string &s, int left, int right) {

        while(left >= 0 && right < s.size() && s[left] == s[right]) {

            if(right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }

            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {

        for(int i = 0; i < s.size(); i++) {

            // Odd length palindrome
            expand(s, i, i);

            // Even length palindrome
            expand(s, i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution solution;
    string s = "babad";
    string result = solution.longestPalindrome(s);
    cout << result << endl; // Output: "bab" or "aba"
    return 0;
}