class Solution {
public:
    int nthRoot(int n, int m) {
        // Loop from 1 to m
        for (int i = 1; i <= m; i++) {
            // Compute i^n
            long long power = pow(i, n);

            // If equal to m, return i
            if (power == m) return i;

            // If exceeds m, break
            if (power > m) break;
        }

        // If not found, return -1
        return -1;
    }
};
