#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int num : nums1){
            int index = -1;
            for(int i=0;i<nums2.size();i++){
                if(nums2[i] == num) {
                    index = i;
                    break;
                }
            }
            int greater = -1;
            for(int i=index+1;i<nums2.size();i++){
                if(nums2[i] > num) {
                    greater = nums2[i];
                    break;
                }
            }
            ans.push_back(greater);
        }
        return ans;
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
    cout << endl;
    
    return 0;
}