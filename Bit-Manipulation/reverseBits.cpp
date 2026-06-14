// reverse bits 190
// leetcode: https://leetcode.com/problems/reverse-bits/

*********************************************************Brute Solution**************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string binary = "";

        // Step 1: Convert number to 32-bit binary string
        for (int i = 0; i < 32; i++) {
            if (n & 1) {
                binary += '1';
            } else {
                binary += '0';
            }

            // Move to next bit
            n >>= 1;
        }

        // Here binary already stores bits from right to left,
        // which is actually the reversed binary form.

        uint32_t ans = 0;

        // Step 2: Convert binary string back to integer
        for (int i = 0; i < 32; i++) {
            ans = ans * 2 + (binary[i] - '0');
        }

        return ans;
    }
};
*********************************************************Better Solution**************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {
            // Make space in ans for the next bit
            ans <<= 1;

            // Extract the last bit of n
            uint32_t lastBit = n & 1;

            // Add this bit to ans
            ans |= lastBit;

            // Remove the last bit from n
            n >>= 1;
        }

        return ans;
    }
};
*********************************************************Optimal Solution**************************************************************************************

class Solution {
private:
    unordered_map<uint32_t, uint32_t> cache;

    // Reverse only 8 bits
    uint32_t reverseByte(uint32_t byte) {
        if (cache.count(byte)) {
            return cache[byte];
        }

        uint32_t original = byte;
        uint32_t ans = 0;

        for (int i = 0; i < 8; i++) {
            ans <<= 1;
            ans |= (byte & 1);
            byte >>= 1;
        }

        cache[original] = ans;
        return ans;
    }

public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        // Process 4 bytes
        for (int i = 0; i < 4; i++) {
            // Extract last 8 bits
            uint32_t byte = n & 255;

            // Reverse this byte
            uint32_t reversedByte = reverseByte(byte);

            // Place reversed byte in answer
            ans <<= 8;
            ans |= reversedByte;

            // Move to next byte
            n >>= 8;
        }

        return ans;
    }
};

