#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main() {
    Solution solution;
    string haystack = "hello";
    string needle = "ll";
    int index = solution.strStr(haystack, needle);
    cout << "Index of first occurrence: " << index << endl; // Output: 2
    return 0;
}