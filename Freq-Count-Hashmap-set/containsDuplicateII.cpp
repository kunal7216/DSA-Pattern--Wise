*****************************************************************Brute Solution*************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        // Check every pair of indices
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // If distance becomes greater than k,
                // no need to check further for this i
                if (j - i > k) {
                    break;
                }

                // Same value found within distance k
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};
*****************************************************************Better Solution*************************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];

            // If value was seen before
            if (lastIndex.find(value) != lastIndex.end()) {

                // Check distance between current index and last index
                if (i - lastIndex[value] <= k) {
                    return true;
                }
            }

            // Update latest index of this value
            lastIndex[value] = i;
        }

        return false;
    }
};
*****************************************************************Optimal solution*************************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {

            // If current element already exists in last k elements
            if (window.find(nums[i]) != window.end()) {
                return true;
            }

            // Add current element into window
            window.insert(nums[i]);

            // Keep window size at most k
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};
