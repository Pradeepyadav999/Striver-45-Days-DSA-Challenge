class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n <= 0)
            return false;

        return (n & (n - 1)) == 0;
    }
};


// Time  : O(1)
// Space : O(1)