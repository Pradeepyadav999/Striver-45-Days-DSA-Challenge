// Its same as the kth largest element in an array problem. We can use a min heap of size k to keep track of the k largest elements seen so far. The top of the min heap will be the kth largest element.
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // It remove duplicates
        unordered_set<int> st(nums.begin(), nums.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int num : st) {
            pq.push(num);
            if(pq.size() > 3)
                pq.pop();
        }
        // When size is less than 3 we return maximum 
        if(pq.size() < 3) {
            while(pq.size() > 1)
                pq.pop();
            return pq.top();
        }
        return pq.top();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << sol.thirdMax(nums) << endl; 
    return 0;
}