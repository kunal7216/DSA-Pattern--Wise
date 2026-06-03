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


************************************************************************Brute Solution***********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        // For each index i, calculate sum from 0 to i
        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = 0; j <= i; j++) {
                sum += nums[j];
            }

            ans[i] = sum;
        }

        return ans;
    }
};
************************************************************************Better Solution**********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();

        // Start from index 1 because index 0 remains same
        for (int i = 1; i < n; i++) {
            // nums[i - 1] already contains running sum up to previous index
            nums[i] = nums[i] + nums[i - 1];
        }

        return nums;
    }
};
************************************************************************Optimal Solution**********************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();

        // Start from index 1 because index 0 remains same
        for (int i = 1; i < n; i++) {
            // nums[i - 1] already contains running sum up to previous index
            nums[i] = nums[i] + nums[i - 1];
        }

        return nums;
    }
};
