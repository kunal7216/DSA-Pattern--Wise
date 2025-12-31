class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        // Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {

            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int j = i + 1; // Left pointer
            int k = n - 1; // Right pointer

            while (j < k)
            {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0)
                {
                    // Sum is too large, need a smaller number
                    k--;
                }
                else if (total < 0)
                {
                    // Sum is too small, need a larger number
                    j++;
                }
                else
                {
                    // Found a triplet
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;

                    // Skip duplicate values for the second element
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                }
            }
        }
        return res;
    }
};