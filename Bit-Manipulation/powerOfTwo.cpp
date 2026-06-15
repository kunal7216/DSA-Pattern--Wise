// power of two
// leetcode: https://leetcode.com/problems/power-of-two/


**********************************************************Brute Solution**********************************************************************************
    class Solution {
public:
    bool isPowerOfTwo(int n) {

        // Negative numbers and 0
        // cannot be powers of 2
        if (n <= 0) {
            return false;
        }

        // Keep dividing by 2
        while (n % 2 == 0) {
            n = n / 2;
        }

        // If finally becomes 1
        // then it is power of 2
        return n == 1;
    }
};
**********************************************************Better Solution**********************************************************************************
    class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n <= 0) {
            return false;
        }

        int count = 0;

        while (n > 0) {

            // Check last bit
            if (n & 1) {
                count++;
            }

            n = n >> 1;
        }

        return count == 1;
    }
};
**********************************************************Optimal Solution**********************************************************************************

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
