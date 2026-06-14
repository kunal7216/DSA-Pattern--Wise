// number of 1 bits 191
// leetcode: https://leetcode.com/problems/number-of-1-bits/

*******************************************************Brute Solution****************************************************************************************
    class Solution {
public:
    int hammingWeight(uint32_t n) {
        string binary = "";

        // Convert number to binary string
        while (n > 0) {
            int bit = n % 2;

            if (bit == 1) {
                binary += '1';
            } else {
                binary += '0';
            }

            n = n / 2;
        }

        int count = 0;

        // Count number of '1' characters
        for (char ch : binary) {
            if (ch == '1') {
                count++;
            }
        }

        return count;
    }
};
*******************************************************Better Solution****************************************************************************************
    class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n > 0) {
            // If last bit is 1, increase count
            if (n & 1) {
                count++;
            }

            // Remove the last bit
            n = n >> 1;
        }

        return count;
    }
};
*******************************************************Optimal Solution****************************************************************************************
    class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n != 0) {
            // Remove the rightmost set bit
            n = n & (n - 1);

            // One set bit was removed
            count++;
        }

        return count;
    }
};
