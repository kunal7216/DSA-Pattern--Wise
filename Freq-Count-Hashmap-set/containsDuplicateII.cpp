class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        // HashMap to store the last index at which each value was seen
        unordered_map<int, int> seen;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++)
        {
            int val = nums[i];

            // Check if the value has been seen before
            // and whether the distance between indices is <= k
            if (seen.find(val) != seen.end() && i - seen[val] <= k)
            {
                return true; // Nearby duplicate found
            }

            // Update the index of the current value
            // (always store the most recent index)
            seen[val] = i;
        }

        // No nearby duplicates found
        return false;
    }
};
