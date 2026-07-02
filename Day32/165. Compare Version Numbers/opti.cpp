#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        int i = 0, j = 0;
        int n = version1.size();
        int m = version2.size();

        while (i < n || j < m) {

            long long num1 = 0;
            long long num2 = 0;

            // Extract current revision from version1
            while (i < n && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            // Extract current revision from version2
            while (j < m && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            // Compare current revisions
            if (num1 < num2)
                return -1;
            if (num1 > num2)
                return 1;

            // Skip '.'
            i++;
            j++;
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