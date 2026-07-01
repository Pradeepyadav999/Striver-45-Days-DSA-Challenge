class Solution {
public:
    vector<int> search(string &pat, string &txt) {

        string s = pat + "$" + txt;

        int n = s.size();
        int m = pat.size();

        vector<int> z(n, 0);
        vector<int> ans;

        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {

            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);

            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;

            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }

            if (z[i] == m)
                ans.push_back(i - m - 1);
        }

        return ans;
    }
};