// power of two
// leetcode: https://leetcode.com/problems/power-of-two/

class Solution {
public: 
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return (n & (n - 1)) == 0;

        // Condition 1: n must be positive
        // Condition 2: n & (n - 1) == 0 → only true for powers of two
        // return n > 0 && !(n & (n-1)); // alternative approach
    }
};