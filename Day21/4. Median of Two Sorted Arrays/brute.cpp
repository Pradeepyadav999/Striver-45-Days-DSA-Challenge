class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> temp;
        for(int num : nums1)
            temp.push_back(num);
        for(int num : nums2)
            temp.push_back(num);
        sort(temp.begin(), temp.end());
        int size = temp.size();
        int mid = size / 2;
        if(size % 2 == 0) {
            return (temp[mid - 1] + temp[mid]) / 2.0;
        } else {
            return temp[mid];
        }
    }
};