#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int freq[26]={0};
        for (char c : s)
            freq[c - 'a']++;
        for (char c : t)
            freq[c - 'a']--;
        for (int count : freq) {
            if (count != 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    bool result = solution.isAnagram(s, t);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}