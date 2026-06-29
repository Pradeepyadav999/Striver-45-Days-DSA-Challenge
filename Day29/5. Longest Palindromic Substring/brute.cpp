#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int start=0;
        int maxLen=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    if(j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
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