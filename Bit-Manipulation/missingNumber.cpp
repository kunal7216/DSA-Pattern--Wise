// missing number 
// leetcode 268
// https://leetcode.com/problems/missing-number/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ans = 0;         // Initialize result variable
        int n = nums.size(); // Total number of expected elements (0 to n)

        // XOR all elements in the array with their indices
        for (int i = 0; i < n; i++)
        {
            // XOR cancels out numbers appearing in both array and indices
            ans ^= (nums[i] ^ i);
        }

        // XOR the last number 'n', which is not included in indices
        ans ^= n;

        // The remaining value is the missing number
        return ans;
    }
};
