// single number 2
// leetcode 137
// link: https://leetcode.com/problems/single-number-ii/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        // 'ones' will store bits that have appeared exactly once
        int ones = 0;

        // 'twos' will store bits that have appeared exactly twice
        int twos = 0;

        // Traverse each number in the array
        for (const int num : nums)
        {

            /*
             Update 'ones':
             - (num & ~twos) ensures that bits already present in 'twos'
               (i.e., appeared twice) are not added again.
             - XOR (^) toggles bits:
               - Adds bits appearing for the first time
               - Removes bits appearing for the third time
            */
            ones ^= (num & ~twos);

            /*
             Update 'twos':
             - (num & ~ones) ensures that bits just added to 'ones'
               are not immediately added to 'twos'.
             - XOR toggles bits that have appeared exactly twice
            */
            twos ^= (num & ~ones);
        }

        /*
         After processing all numbers:
         - Bits that appeared three times are removed from both 'ones' and 'twos'
         - 'ones' contains only the bits of the number that appeared once
        */
        return ones;
    }
};
