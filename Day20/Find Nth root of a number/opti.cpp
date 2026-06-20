class Solution {
public:
    long long power(long long mid, int N, int M) {
        long long ans = 1;
        for(int i = 0; i < N; i++) {
            ans *= mid;
            if(ans > M)
                return ans;
        }
        return ans;
    }
    int NthRoot(int N, int M) {
        // Edge Cases
        if(M == 0) return 0;
        if(M == 1) return 1;

        long long low = 1, high = M;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = power(mid, N, M);
            if(val == M)
                return mid;
            else if(val > M)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};