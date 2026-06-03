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

****************************************************************Brute Solution**************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // Try every starting index
        for (int i = 0; i < n; i++) {
            // Try every ending index
            for (int j = i; j < n; j++) {
                int sum = 0;

                // Calculate sum of subarray nums[i...j]
                for (int x = i; x <= j; x++) {
                    sum += nums[x];
                }

                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
****************************************************************Better Solution**************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // Fix starting index
        for (int i = 0; i < n; i++) {
            int sum = 0;

            // Extend ending index
            for (int j = i; j < n; j++) {
                sum += nums[j];

                // nums[i...j] has sum k
                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
****************************************************************Optimal Solution**************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Empty prefix sum exists once
        // This helps count subarrays starting from index 0
        freq[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            // We need a previous prefix sum:
            // previousPrefixSum = prefixSum - k
            int need = prefixSum - k;

            // If this prefix sum appeared before,
            // all those occurrences create valid subarrays ending at i
            if (freq.find(need) != freq.end()) {
                count += freq[need];
            }

            // Store current prefix sum for future subarrays
            freq[prefixSum]++;
        }

        return count;
    }
};
