class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        // Outer loop picks the first element
        for (int i = 0; i < nums.size(); i++)
        {

            // Inner loop picks the second element
            // Starts from i + 1 to avoid using the same element twice
            for (int j = i + 1; j < nums.size(); j++)
            {

                // Check if the sum of nums[i] and nums[j] equals the target
                if (nums[i] + nums[j] == target)
                    return {i, j}; // Return the indices if a valid pair is found
            }
        }

        // If no such pair exists, return an empty vector
        return {};
    }
};
