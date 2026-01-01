// Bitwise AND of Numbers Range
// leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {

        // This variable counts how many times we shift both numbers
        // It helps us restore the common prefix later
        int shifts = 0;

        /*
         Keep right-shifting both 'left' and 'right' until they become equal.
         As long as left < right, it means there is at least one differing bit
         in the current range, and that bit will become 0 in the final AND.
        */
        while (left < right)
        {

            // Remove the least significant bit from both numbers
            left = left >> 1;
            right = right >> 1;

            // Count the number of shifts performed
            shifts++;
        }

        /*
         At this point, 'left' and 'right' are equal and represent
         the common binary prefix of all numbers in the range.
         Left-shifting restores the prefix to its original position.
        */
        return left << shifts;
    }
};


// 2nd approach
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {

        /*
         Key Idea:
         The expression `right = right & (right - 1)` removes the
         **rightmost set bit** of `right`. By repeatedly doing this,
         we eliminate all bits in `right` that would change across
         the range [left, right], since any fluctuating bit will
         eventually become 0 in the AND result.
        */

        while (left < right)
        {
            // Remove the rightmost set bit from 'right'
            right = right & (right - 1);
        }

        /*
         At this point, 'right' has only the bits that are common
         with 'left' across the entire range.
         ANDing it with 'left' ensures we get the final result.
        */
        return left & right;
    }
};
