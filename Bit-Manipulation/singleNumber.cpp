// single Number
// leetcode: https://leetcode.com/problems/single-number/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        // Variable to store the result
        // Initialized to 0 because XOR with 0 gives the number itself
        int res = 0;

        // Traverse each element in the array
        for (int n : nums)
        {

            // XOR current number with result
            // - n ^ n = 0 (duplicate numbers cancel out)
            // - n ^ 0 = n
            // - XOR is commutative and associative
            res ^= n;
        }

        // At the end, only the number that appeared once remains
        return res;
    }
};
