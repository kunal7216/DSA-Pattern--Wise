********************************************************************Brute Solution************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        // Check every index as possible pivot
        for (int i = 0; i < n; i++) {
            int leftSum = 0;
            int rightSum = 0;

            // Calculate sum of elements before i
            for (int j = 0; j < i; j++) {
                leftSum += nums[j];
            }

            // Calculate sum of elements after i
            for (int j = i + 1; j < n; j++) {
                rightSum += nums[j];
            }

            // If both sides are equal, i is pivot
            if (leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};
********************************************************************Better Solution************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);

        // Build prefix sum array
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        // Build suffix sum array
        suffix[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }

        // Check every index as pivot
        for (int i = 0; i < n; i++) {
            int leftSum = 0;
            int rightSum = 0;

            if (i > 0) {
                leftSum = prefix[i - 1];
            }

            if (i < n - 1) {
                rightSum = suffix[i + 1];
            }

            if (leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};
********************************************************************Optima Solution************************************************************************************


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
