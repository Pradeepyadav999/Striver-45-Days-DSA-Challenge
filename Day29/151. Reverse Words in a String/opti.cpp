#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        stack<string> st;
        string word = "";

        for(char ch : s) {

            if(ch != ' ') {
                word += ch;
            }
            else {
                if(!word.empty()) {
                    st.push(word);
                    word = "";
                }
            }
        }

        if(!word.empty())
            st.push(word);

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();

            if(!st.empty())
                ans += " ";
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