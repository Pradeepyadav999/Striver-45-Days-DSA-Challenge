class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {

        int n1 = a.size();
        int n2 = b.size();

        if(n1 > n2)
            return kthElement(b, a, k);

        int low = max(0, k - n2);
        int high = min(k, n1);

        while(low <= high) {

            int count1 = low + (high - low) / 2;
            int count2 = k - count1;

            int l1 = (count1 == 0) ? INT_MIN : a[count1 - 1];
            int l2 = (count2 == 0) ? INT_MIN : b[count2 - 1];

            int r1 = (count1 == n1) ? INT_MAX : a[count1];
            int r2 = (count2 == n2) ? INT_MAX : b[count2];

            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if(l1 > r2) {
                high = count1 - 1;
            }
            else {
                low = count1 + 1;
            }
        }

        return -1;
    }
};