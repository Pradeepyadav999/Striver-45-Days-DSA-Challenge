#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        stringstream ss1(version1);
        stringstream ss2(version2);

        string rev1, rev2;

        while (true) {

            bool hasRev1 = (bool)getline(ss1, rev1, '.');
            bool hasRev2 = (bool)getline(ss2, rev2, '.');

            int num1 = hasRev1 ? stoi(rev1) : 0;
            int num2 = hasRev2 ? stoi(rev2) : 0;

            if (num1 < num2)
                return -1;

            if (num1 > num2)
                return 1;

            if (!hasRev1 && !hasRev2)
                break;
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