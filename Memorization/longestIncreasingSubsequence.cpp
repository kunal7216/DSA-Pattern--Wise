// longest increasing subsequence 
// leetcode 300
// leetcode problem link: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        // T[i] stores the LIS ending at index i (excluding nums[i] itself)
        vector<int> T(n, 0);

        // Main pointer
        for (int i = 1; i < n; i++)
        {

            // Second pointer
            for (int j = 0; j < i; j++)
            {

                // If current element is greater, it can extend LIS
                if (nums[i] > nums[j])
                {

                    // Update LIS length if better option found
                    if (T[j] + 1 > T[i])
                    {
                        T[i] = T[j] + 1;
                    }
                }
            }
        }

        // Find the maximum value in T[]
        int maxIndex = 0;
        for (int i = 1; i < n; i++)
        {
            if (T[i] > T[maxIndex])
            {
                maxIndex = i;
            }
        }

        // +1 to include the element itself
        return T[maxIndex] + 1;
    }
};
