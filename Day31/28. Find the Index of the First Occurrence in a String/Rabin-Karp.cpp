class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        if (m > n)
            return -1;

        const int BASE = 256;
        const int MOD = 1000000007;

        long long patternHash = 0;
        long long textHash = 0;
        long long power = 1;

        // BASE^(m-1)
        for (int i = 0; i < m - 1; i++)
            power = (power * BASE) % MOD;

        // Initial hash
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * BASE + needle[i]) % MOD;
            textHash = (textHash * BASE + haystack[i]) % MOD;
        }

        // Sliding window
        for (int i = 0; i <= n - m; i++) {

            if (patternHash == textHash) {

                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (haystack[i + j] != needle[j]) {
                        match = false;
                        break;
                    }
                }

                if (match)
                    return i;
            }

            if (i < n - m) {

                textHash =
                    (textHash - haystack[i] * power % MOD + MOD) % MOD;

                textHash =
                    (textHash * BASE + haystack[i + m]) % MOD;
            }
        }

        return -1;
    }
};