class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        // Outer loop picks the first element
        for (int i = 0; i < nums.size(); i++)
        {

            // Inner loop picks the second element
            // Starts from i + 1 to avoid using the same element twice
            for (int j = i + 1; j < nums.size(); j++)
            {

                // Check if the sum of nums[i] and nums[j] equals the target
                if (nums[i] + nums[j] == target)
                    return {i, j}; // Return the indices if a valid pair is found
            }
        }

        // If no such pair exists, return an empty vector
        return {};
    }
};

**************************************************************************Brute Solution********************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // Check every possible pair
        for (int i = 0; i < n; i++) {

            // Start from i + 1 because we cannot use the same element twice
            for (int j = i + 1; j < n; j++) {

                // If the pair sum is equal to target
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        // According to the problem, one answer always exists
        return {};
    }
};
********************************************************************************Better Solution**************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // Store value with original index
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = arr[left].first + arr[right].first;

            // Pair found
            if (sum == target) {
                return {arr[left].second, arr[right].second};
            }

            // Need a bigger sum
            else if (sum < target) {
                left++;
            }

            // Need a smaller sum
            else {
                right--;
            }
        }

        return {};
    }
};
********************************************************************************Optimal Solution**************************************************************************
    
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Stores number as key and its index as value
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];

            // Number required to complete the target sum
            int complement = target - current;

            // If complement already exists, we found the pair
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // Store current number after checking
            // This prevents using the same element twice
            mp[current] = i;
        }

        return {};
    }
};
    
