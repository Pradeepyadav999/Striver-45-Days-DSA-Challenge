#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
        vector<int>answer;
        for(int num : nums1){
            int greater=-1;
            for(int i=mp[num]+1;i<nums2.size();i++){
                if(nums2[i] > num) {
                    greater = nums2[i];
                    break;
                }
            }
            answer.push_back(greater);
        }
        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    
    for(int num : result) {
        cout << num << " ";
    }
    return 0;
}