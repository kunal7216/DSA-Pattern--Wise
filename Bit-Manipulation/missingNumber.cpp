// missing number 
// leetcode 268
// https://leetcode.com/problems/missing-number/

********************************************************Brute Solution************************************************************************************
    class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Check every number from 0 to n
        for (int i = 0; i <= n; i++) {

            bool found = false;

            // Search in array
            for (int j = 0; j < n; j++) {

                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }

            // Missing number found
            if (!found) {
                return i;
            }
        }

        return -1;
    }
};
********************************************************Better Solution************************************************************************************
    class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        // Frequency array
        vector<int> hash(n + 1, 0);

        // Mark existing numbers
        for (int num : nums) {
            hash[num] = 1;
        }

        // Find missing number
        for (int i = 0; i <= n; i++) {

            if (hash[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};
********************************************************Optimal Solution************************************************************************************
    class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        int xor1 = 0;
        int xor2 = 0;

        // XOR from 0 to n
        for (int i = 0; i <= n; i++) {
            xor1 ^= i;
        }

        // XOR all array elements
        for (int num : nums) {
            xor2 ^= num;
        }

        // Missing number
        return xor1 ^ xor2;
    }
};



********************approach 2
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        // Expected sum from 0 to n
        int expectedSum = n * (n + 1) / 2;

        // Actual sum of array
        int actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        // Missing number
        return expectedSum - actualSum;
    }
};
