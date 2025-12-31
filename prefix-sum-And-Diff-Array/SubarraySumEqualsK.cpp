class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        // Hash map to store prefix sum and its frequency
        // Key   -> prefix sum value
        // Value -> number of times this prefix sum has appeared
        unordered_map<int, int> mpp;

        // Initialize with prefix sum 0 having frequency 1
        // This helps handle subarrays starting from index 0
        mpp[0] = 1;

        // presum stores the running prefix sum
        // cmt stores the count of subarrays with sum equal to k
        int presum = 0, cmt = 0;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++)
        {

            // Add current element to prefix sum
            presum += nums[i];

            // We need a previous prefix sum such that:
            // current_prefix_sum - previous_prefix_sum = k
            // => previous_prefix_sum = presum - k
            int remove = presum - k;

            // If such a prefix sum exists in the map,
            // add its frequency to the count
            cmt += mpp[remove];

            // Store the current prefix sum in the map
            // for future subarray calculations
            mpp[presum] += 1;
        }

        // Return total count of subarrays whose sum equals k
        return cmt;
    }
};
