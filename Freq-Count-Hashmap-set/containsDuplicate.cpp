****************************************************************Brute Solution**************************************************************************************
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Compare every pair of elements
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                
                // If two different positions have same value
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        // No duplicate found
        return false;
    }
};
****************************************************************Better Solution**************************************************************************************
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());

        // Check adjacent elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        // No duplicate found
        return false;
    }
};
****************************************************************Optimal solution**************************************************************************************
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            
            // If num already exists in set, duplicate found
            if (seen.find(num) != seen.end()) {
                return true;
            }

            // Otherwise store this number
            seen.insert(num);
        }

        // No duplicate found
        return false;
    }
};
