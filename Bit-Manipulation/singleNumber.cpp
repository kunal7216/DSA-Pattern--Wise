// single Number
// leetcode: https://leetcode.com/problems/single-number/

***********************************************************Brute Solution************************************************************************************
    class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        // Check every element one by one
        for (int i = 0; i < n; i++) {
            int count = 0;

            // Count frequency of nums[i]
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            // The element that appears only once is the answer
            if (count == 1) {
                return nums[i];
            }
        }

        return -1; // This line will never be reached for valid input
    }
};
***********************************************************Better Solution************************************************************************************
    
    class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequency of every number
        for (int num : nums) {
            freq[num]++;
        }

        // Find the number whose frequency is 1
        for (auto it : freq) {
            if (it.second == 1) {
                return it.first;
            }
        }

        return -1; // This line will never be reached for valid input
    }
};
***********************************************************Optimal Solution************************************************************************************
    class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorValue = 0;

        // XOR all numbers
        // Duplicate numbers cancel each other
        for (int num : nums) {
            xorValue = xorValue ^ num;
        }

        // Remaining value is the single number
        return xorValue;
    }
};
