// minimum sub array
// leetcode 53
// https://leetcode.com/problems/maximum-subarray/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // To find the maximum sum possible overall
        int max_so_far = nums[0];

        // To store the maximum subarray sum ending at the current position
        int curr_max = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            // Step 1: Extend the previous subarray or start new from current element
            curr_max = std::max(nums[i], nums[i] + curr_max);

            // Step 2: Update overall maximum sum
            max_so_far = std::max(curr_max, max_so_far);
        }

        return max_so_far; // Maximum subarray sum
    }
};
