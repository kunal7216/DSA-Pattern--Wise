class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {

        // Create a result array of same size as nums, initialized with 0
        vector<int> res(nums.size(), 0);

        // Left pointer starting from beginning of array
        int left = 0;

        // Right pointer starting from end of array
        int right = nums.size() - 1;

        // Traverse from the last index to the first index of result array
        // because we want to place the largest square first
        for (int i = nums.size() - 1; i >= 0; i--)
        {

            // Compare absolute values at left and right pointers
            if (abs(nums[left]) > abs(nums[right]))
            {

                // If left value has larger absolute value,
                // its square will be larger
                res[i] = nums[left] * nums[left];

                // Move left pointer forward
                left++;
            }
            else
            {

                // If right value has larger or equal absolute value,
                // its square will be larger
                res[i] = nums[right] * nums[right];

                // Move right pointer backward
                right--;
            }
        }

        // Return the sorted squares array
        return res;
    }
};
