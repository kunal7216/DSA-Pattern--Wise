// single number 2
// leetcode 137
// link: https://leetcode.com/problems/single-number-ii/

******************************************************Brute Solution**************************************************************************************

    class Solution {
public:
    int singleNumber(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {

            int count = 0;

            // Count frequency
            for (int j = 0; j < nums.size(); j++) {

                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            // Unique element
            if (count == 1) {
                return nums[i];
            }
        }

        return -1;
    }
};
******************************************************Better Solution**************************************************************************************

    class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Find unique element
        for (auto it : freq) {

            if (it.second == 1) {
                return it.first;
            }
        }

        return -1;
    }
};
******************************************************Optimal Solution**************************************************************************************

    class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = 0;

        // Check all 32 bits
        for (int bit = 0; bit < 32; bit++) {

            int count = 0;

            // Count set bits
            for (int num : nums) {

                // Check if current bit is set
                if ((num >> bit) & 1) {
                    count++;
                }
            }

            // Unique bit remains
            if (count % 3 != 0) {
                result |= (1 << bit);
            }
        }

        return result;
    }
};
