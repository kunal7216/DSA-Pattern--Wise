class NumArray
{
public:
    vector<int> &presum;
    // Reference to a vector that will store prefix sums.
    // Each index i stores the sum of elements from 0 to i.

    NumArray(vector<int> &nums) : presum(nums)
    {
        // Constructor initializes 'presum' as a reference to 'nums'
        // This avoids creating a new array and uses the same memory.

        for (int i = 1; i < presum.size(); i++)
            // Build the prefix sum array
            // Add previous sum to current element
            presum[i] += presum[i - 1];
    }

    int sumRange(int left, int right)
    {
        // Returns the sum of elements between indices left and right (inclusive)

        if (left == 0)
            // If the range starts from index 0,
            // the sum is directly the prefix sum at 'right'
            return presum[right];

        // Otherwise, subtract prefix sum before 'left'
        // This removes the sum of elements [0, left-1]
        return presum[right] - presum[left - 1];
    }
};
