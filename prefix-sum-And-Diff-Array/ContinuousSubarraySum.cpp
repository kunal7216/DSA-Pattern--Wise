class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {

        // Hash map to store:
        // key   -> remainder of prefix sum % k
        // value -> earliest index where this remainder occurred
        unordered_map<int, int> mp;

        // Initialize remainder 0 at index -1
        // This helps handle cases where a valid subarray starts from index 0
        mp[0] = -1;

        // Variable to maintain prefix sum
        int sum = 0;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++)
        {

            // Add current element to prefix sum
            sum += nums[i];

            // Calculate remainder of prefix sum with k
            int rem = sum % k;

            // If this remainder has been seen before
            if (mp.find(rem) != mp.end())
            {

                // Check if the subarray length is at least 2
                // i - previous_index >= 2 ensures size >= 2
                if (i - mp[rem] >= 2)
                    return true;
            }
            else
            {
                // Store the first occurrence of this remainder
                // We store only the earliest index to maximize subarray length
                mp[rem] = i;
            }
        }

        // No valid subarray found
        return false;
    }
};
