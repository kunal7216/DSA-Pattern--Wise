// longest increasing subsequence 
// leetcode 300
// leetcode problem link: https://leetcode.com/problems/longest-increasing-subsequence/

// ================================
// Approach 1: Brute Force (Recursion)
// Time Complexity: O(2^n)
// Space Complexity: O(n)
// ================================

class Solution {
public:

    int solve(vector<int>& nums, int index, int prevIndex)
    {
        // If all elements processed
        if(index == nums.size())
            return 0;

        // Option 1: Skip current element
        int notTake = solve(nums, index + 1, prevIndex);

        // Option 2: Take current element
        int take = 0;

        if(prevIndex == -1 || nums[index] > nums[prevIndex])
        {
            take = 1 + solve(nums, index + 1, index);
        }

        return max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, -1);
    }
};

// ===================================
// Approach 2: DP (Tabulation)
// Time Complexity: O(n²)
// Space Complexity: O(n)
// ===================================

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n,1);

        int ans = 1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }

            ans=max(ans,dp[i]);
        }

        return ans;
    }
};

// =======================================
// Approach 3: Greedy + Binary Search
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// =======================================

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> tails;

        for(int x : nums)
        {
            // Find first element >= x
            auto it = lower_bound(tails.begin(), tails.end(), x);

            if(it == tails.end())
            {
                // Extend LIS
                tails.push_back(x);
            }
            else
            {
                // Replace with smaller ending value
                *it = x;
            }
        }

        return tails.size();
    }
};
