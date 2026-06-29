#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());

        string ans;
        int n = s.size();
        int i = 0;

        while(i < n) {

            while(i < n && s[i] == ' ')
                i++;

            if(i >= n)
                break;

            string word;

            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if(!ans.empty())
                ans += " ";

            ans += word;
        }

        return ans;
    }
};


int main() {
    Solution solution;
    string s = "  Hello   World  ";
    string result = solution.reverseWords(s);
    cout << "\"" << result << "\"" << endl; // Output: "World Hello"
    return 0;
}