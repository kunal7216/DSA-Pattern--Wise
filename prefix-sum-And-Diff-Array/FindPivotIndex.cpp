class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int totalSum = 0;
        for (int x : nums)
        {
            totalSum += x; // Sum of all elements
        }

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // Right sum = totalSum - leftSum - nums[i]
            if (leftSum == totalSum - leftSum - nums[i])
            {
                return i; // Pivot index found
            }
            leftSum += nums[i];
        }

        return -1; // No pivot index
    }
};
