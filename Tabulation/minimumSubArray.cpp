// minimum sub array
// leetcode 53
// https://leetcode.com/problems/maximum-subarray/

// ==============================
// Approach 1 : Brute Force
// Time Complexity : O(N^3)
// Space Complexity : O(1)
// ==============================

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        int ans = INT_MIN;

        // Choose starting index
        for(int i = 0; i < n; i++){

            // Choose ending index
            for(int j = i; j < n; j++){

                int sum = 0;

                // Calculate subarray sum
                for(int k = i; k <= j; k++)
                    sum += nums[k];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};


// ==============================
// Approach 2 : Better
// Time Complexity : O(N^2)
// Space Complexity : O(1)
// ==============================

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        int ans = INT_MIN;

        // Select starting index
        for(int i = 0; i < n; i++){

            int sum = 0;

            // Extend subarray
            for(int j = i; j < n; j++){

                sum += nums[j];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};

// ==============================
// Approach 3 : Optimal (Kadane's Algorithm)
// Time Complexity : O(N)
// Space Complexity : O(1)
// ==============================

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Current subarray sum
        int currentSum = 0;

        // Stores maximum answer
        int maxSum = nums[0];

        // Traverse array once
        for(int num : nums){

            // If current sum is negative,
            // discard it because it will only
            // reduce future sums.
            if(currentSum < 0)
                currentSum = 0;

            // Extend current subarray
            currentSum += num;

            // Update maximum answer
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
