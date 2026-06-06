// first missing positive number 
// Problem Link: https://leetcode.com/problems/first-missing-positive/
// this question is solved based on frequency count hashmap and set

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {

        // Map to store frequency of each number in the array
        map<int, int> mp;

        // Store all elements of nums into the map
        for (auto i : nums)
            mp[i]++;

        // The smallest missing positive must lie in range [1, n+1]
        // We check from 1 up to nums.size() + 1
        for (int i = 1; i <= nums.size() + 1; i++)
        {

            // If a number i is not present in the map,
            // then it is the first missing positive
            if (mp[i] == 0)
                return i;
        }

        // This line is technically redundant because
        // we will always return inside the loop
        return nums.size() + 1;
    }
};


*************************************************************Brute Solution*******************************************************************************


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Check every possible answer from 1 to n + 1
        for (int target = 1; target <= n + 1; target++) {
            bool found = false;

            // Search target in the whole array
            for (int i = 0; i < n; i++) {
                if (nums[i] == target) {
                    found = true;
                    break;
                }
            }

            // First positive number which is not found is the answer
            if (!found) {
                return target;
            }
        }

        return n + 1;
    }
};
*************************************************************Better Solution*******************************************************************************


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int missing = 1;

        for (int i = 0; i < nums.size(); i++) {
            // Ignore negative numbers and zero
            if (nums[i] <= 0) {
                continue;
            }

            // If current number is equal to missing,
            // then we found this number and now need next one
            if (nums[i] == missing) {
                missing++;
            }

            // If current number is greater than missing,
            // then missing is not present
            else if (nums[i] > missing) {
                return missing;
            }

            // If nums[i] < missing, it is duplicate or already handled
        }

        return missing;
    }
};
*************************************************************Optimal Solution*******************************************************************************

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Place each number x at index x - 1
        for (int i = 0; i < n; i++) {

            // Keep swapping until nums[i] is at its correct position
            while (
                nums[i] >= 1 && 
                nums[i] <= n && 
                nums[nums[i] - 1] != nums[i]
            ) {
                int correctIndex = nums[i] - 1;
                swap(nums[i], nums[correctIndex]);
            }
        }

        // Step 2: Find first index where nums[i] != i + 1
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // Step 3: If all numbers 1 to n are present
        return n + 1;
    }
};
