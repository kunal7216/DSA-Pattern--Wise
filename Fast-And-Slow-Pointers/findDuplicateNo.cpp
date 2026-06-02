******************************************************************Brute Solution**************************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Check every pair of elements
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // If two values are equal, we found the duplicate
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }

        return -1;
    }
};
******************************************************************Better Solution**************************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        // visited[x] tells whether x has appeared before
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            int value = nums[i];

            // If value is already visited, it is the duplicate
            if (visited[value] == 1) {
                return value;
            }

            // Mark value as visited
            visited[value] = 1;
        }

        return -1;
    }
};
******************************************************************Optimal Solution**************************************************************************************
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        // Initialize slow and fast pointers
        // Both start from the value at index 0
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect the cycle
        // Move slow by 1 step and fast by 2 steps
        do
        {
            slow = nums[slow];       // Move slow pointer one step
            fast = nums[nums[fast]]; // Move fast pointer two steps
        } while (slow != fast); // Loop until they meet

        // Phase 2: Find the entrance of the cycle (duplicate number)
        // Reset fast pointer to the start
        fast = nums[0];

        // Move both pointers one step at a time
        // The point where they meet is the duplicate number
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        // Return the duplicate number
        return slow;
    }
};
