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


************************************************************************Brute Solution**********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // Try every starting index
        for (int i = 0; i < n; i++) {
            // Try every ending index
            for (int j = i + 1; j < n; j++) {
                int sum = 0;

                // Calculate sum from i to j
                for (int x = i; x <= j; x++) {
                    sum += nums[x];
                }

                // Check if sum is multiple of k
                if (sum % k == 0) {
                    return true;
                }
            }
        }

        return false;
    }
};
*************************************************************************Bettter Solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // Fix starting index
        for (int i = 0; i < n; i++) {
            int sum = 0;

            // Extend ending index
            for (int j = i; j < n; j++) {
                sum += nums[j];

                // Length of subarray = j - i + 1
                if (j - i + 1 >= 2 && sum % k == 0) {
                    return true;
                }
            }
        }

        return false;
    }
};
*************************************************************************Optimal Solution*********************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> firstIndex;

        // Remainder 0 exists before array starts
        // This helps detect subarrays starting from index 0
        firstIndex[0] = -1;

        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int remainder = prefixSum % k;

            // If same remainder was seen before,
            // subarray between previous index + 1 and i
            // has sum divisible by k
            if (firstIndex.find(remainder) != firstIndex.end()) {
                int length = i - firstIndex[remainder];

                if (length >= 2) {
                    return true;
                }
            } 
            else {
                // Store only first occurrence
                firstIndex[remainder] = i;
            }
        }

        return false;
    }
};

