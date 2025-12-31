// number of 1 bits
// leetcode: https://leetcode.com/problems/number-of-1-bits/

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {

        // Variable to count the number of set bits (1s)
        int res = 0;

        // Loop through all 32 bits of the integer
        for (int i = 0; i < 32; i++)
        {

            // Right shift n by i positions
            // AND with 1 to check if the ith bit is set
            if ((n >> i) & 1)
            {
                // If the bit is 1, increment the count
                res += 1;
            }
        }

        // Return total count of set bits
        return res;
    }
};
