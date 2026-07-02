#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        vector<int> v1, v2;
        string temp = "";

        // Split version1
        for (char c : version1) {
            if (c == '.') {
                v1.push_back(stoi(temp));
                temp = "";
            } else {
                temp += c;
            }
        }
        v1.push_back(stoi(temp));

        // Split version2
        temp = "";
        for (char c : version2) {
            if (c == '.') {
                v2.push_back(stoi(temp));
                temp = "";
            } else {
                temp += c;
            }
        }
        v2.push_back(stoi(temp));

        int n = max(v1.size(), v2.size());

        for (int i = 0; i < n; i++) {

            int num1 = (i < v1.size()) ? v1[i] : 0;
            int num2 = (i < v2.size()) ? v2[i] : 0;

            if (num1 < num2)
                return -1;

            if (num1 > num2)
                return 1;
        }

        return 0;
    }
};

int main() {
    Solution s;
    string version1, version2;
    cin >> version1 >> version2;
    cout << s.compareVersion(version1, version2);
}