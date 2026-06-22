#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> solve(vector<int> &a,vector<int> &b,int k) {

        int n = a.size();

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        priority_queue<
            pair<int,pair<int,int>>
        > pq;

        set<pair<int,int>> visited;

        pq.push({a[0]+b[0], {0,0}});
        visited.insert({0,0});

        vector<int> ans;

        while(k--) {

            auto top = pq.top();
            pq.pop();

            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second  ;

            ans.push_back(sum);

            if(i+1 < n &&
               visited.find({i+1,j})
               == visited.end()) {

                pq.push({
                    a[i+1]+b[j],
                    {i+1,j}
                });

                visited.insert({i+1,j});
            }

            if(j+1 < n &&
               visited.find({i,j+1})
               == visited.end()) {

                pq.push({
                    a[i]+b[j+1],
                    {i,j+1}
                });

                visited.insert({i,j+1});
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 4, 2};
    vector<int> b = {3, 5, 1};
    int k = 3;
    vector<int> result = sol.solve(a, b, k);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 9 8 7
    return 0;
}