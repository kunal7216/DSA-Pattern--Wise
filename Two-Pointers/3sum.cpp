class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        // Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {

            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int j = i + 1; // Left pointer
            int k = n - 1; // Right pointer

            while (j < k)
            {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0)
                {
                    // Sum is too large, need a smaller number
                    k--;
                }
                else if (total < 0)
                {
                    // Sum is too small, need a larger number
                    j++;
                }
                else
                {
                    // Found a triplet
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;

                    // Skip duplicate values for the second element
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                }
            }
        }
        return res;
    }
};

***********************************************************************Brute Solution**************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // Set stores only unique triplets
        set<vector<int>> uniqueTriplets;

        // Try every possible triplet
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {

                    // Check if the sum of three numbers is zero
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};

                        // Sort triplet so that duplicates are treated the same
                        sort(triplet.begin(), triplet.end());

                        // Insert into set to avoid duplicates
                        uniqueTriplets.insert(triplet);
                    }
                }
            }
        }

        // Convert set to vector
        vector<vector<int>> answer;
        for (auto triplet : uniqueTriplets) {
            answer.push_back(triplet);
        }

        return answer;
    }
};
************************************************************************Better Solution*************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // Set stores unique sorted triplets
        set<vector<int>> uniqueTriplets;

        // Fix one number
        for (int i = 0; i < n; i++) {

            // Stores numbers seen after index i
            unordered_set<int> seen;

            for (int j = i + 1; j < n; j++) {

                // Required third number
                int third = -(nums[i] + nums[j]);

                // If third already exists, triplet is found
                if (seen.find(third) != seen.end()) {
                    vector<int> triplet = {nums[i], nums[j], third};

                    // Sort triplet to remove duplicate ordering
                    sort(triplet.begin(), triplet.end());

                    // Set removes duplicates
                    uniqueTriplets.insert(triplet);
                }

                // Mark current number as seen
                seen.insert(nums[j]);
            }
        }

        // Convert set to vector
        vector<vector<int>> answer;
        for (auto triplet : uniqueTriplets) {
            answer.push_back(triplet);
        }

        return answer;
    }
};
***************************************************************************Optimal Solution**********************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;

        int n = nums.size();

        // Sort array for two-pointer logic and duplicate handling
        sort(nums.begin(), nums.end());

        // Fix one number
        for (int i = 0; i < n; i++) {

            // Skip duplicate fixed elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            // Solve 2Sum for the remaining part
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    answer.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate left values
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if (sum < 0) {
                    // Need a larger sum
                    left++;
                }
                else {
                    // Need a smaller sum
                    right--;
                }
            }
        }

        return answer;
    }
};
