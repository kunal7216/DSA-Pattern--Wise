// reverse bits
// leetcode: https://leetcode.com/problems/reverse-bits/

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {

        // Variable to store the reversed bits
        uint32_t ans = 0;

        // Loop through all 32 bits of the number
        for (int i = 0; i < 32; i++)
        {

            // Shift ans to the left to make space for the next bit
            ans <<= 1;

            // Extract the least significant bit of n
            // and place it in ans
            ans |= (n & 1);

            // Shift n to the right to process the next bit
            n >>= 1;
        }

        // Return the final reversed 32-bit number
        return ans;
    }
};
