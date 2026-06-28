#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxOfWindow(vector<int>& arr, int window) {
        vector<int> minimum;
        for(int i = 0; i <= arr.size() - window; i++) {
            int mini = arr[i];
            for(int j = i; j < i + window; j++) {
                mini = min(mini, arr[j]);
            }
            minimum.push_back(mini);
        }
        return *max_element(minimum.begin(), minimum.end());
    }

    vector<int> maxOfMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> answer;
        for(int window = 1; window <= n; window++) {
            answer.push_back(maxOfWindow(arr, window));
        }
        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> result = solution.maxOfMin(arr);
    for(int val : result) {
        cout << val << " ";
    }
    return 0;
}