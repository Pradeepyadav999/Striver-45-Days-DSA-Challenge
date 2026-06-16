#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<long long>& val,  vector<long long>& wt, long long capacity) {

        int n = val.size();

        vector<pair<double,int>> items;

        for(int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, i});
        }

        sort(items.begin(), items.end(), greater<pair<double,int>>());

        double maxValue = 0.0;

        for(int i = 0; i < n; i++) {
            int idx = items[i].second;

            if(wt[idx] <= capacity) {
                maxValue += val[idx];
                capacity -= wt[idx];
            }
            else {
                maxValue += items[i].first * capacity;
                break;
            }
        }

        return maxValue;
    }
};

int main() {

    vector<long long> val = {100, 60, 120};
    vector<long long> wt = {20, 10, 30};

    long long capacity = 50;

    Solution obj;

    double ans = obj.fractionalKnapsack(val, wt, capacity);

    cout << fixed << setprecision(2) << ans;

    return 0;
}