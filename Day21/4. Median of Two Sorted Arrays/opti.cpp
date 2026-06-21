class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        int n = n1 + n2;

        int ind2 = n / 2;
        int ind1 = ind2 - 1;

        int i = 0, j = 0;
        int cnt = 0;

        int ele1 = -1, ele2 = -1;

        while(i < n1 && j < n2) {

            int val;

            if(nums1[i] <= nums2[j])
                val = nums1[i++];
            else
                val = nums2[j++];

            if(cnt == ind1) ele1 = val;
            if(cnt == ind2) ele2 = val;

            cnt++;
        }

        while(i < n1) {

            int val = nums1[i++];

            if(cnt == ind1) ele1 = val;
            if(cnt == ind2) ele2 = val;

            cnt++;
        }

        while(j < n2) {

            int val = nums2[j++];

            if(cnt == ind1) ele1 = val;
            if(cnt == ind2) ele2 = val;

            cnt++;
        }

        if(n % 2 == 1)
            return ele2;

        return (ele1 + ele2) / 2.0;
    }
};