class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        // Loop starts from index 1 because the first element
        // does not need any previous sum
        for (int i = 1; i < nums.size(); i++)
            // Add the previous element's value (which already contains
            // the running sum up to index i-1) to the current element
            nums[i] += nums[i - 1];

        // Return the modified array containing running sums
        return nums;
    }
};
