// LeetCode 496: Next Greater Element I
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        // Map to store: value in nums2 -> its next greater element
        unordered_map<int, int> next;

        // Stack to maintain a decreasing (monotonic) stack
        // It stores elements from nums2
        stack<int> s;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i)
        {

            // Remove all elements from stack that are
            // smaller than or equal to current element
            // because they can never be the "next greater"
            while (!s.empty() && s.top() <= nums2[i])
            {
                s.pop();
            }

            // If stack is empty, no greater element on the right
            // otherwise, the top of stack is the next greater element
            next[nums2[i]] = s.empty() ? -1 : s.top();

            // Push current element into stack
            s.push(nums2[i]);
        }

        // Result vector for nums1
        vector<int> res;

        // For each element in nums1,
        // fetch its next greater element from the map
        for (int num : nums1)
        {
            res.push_back(next[num]);
        }

        // Return the final result
        return res;
    }
};


******************************************************************Brute solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        // Traverse every element of nums1
        for (int i = 0; i < nums1.size(); i++) {
            int target = nums1[i];

            // Step 1: Find target in nums2
            int index = -1;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == target) {
                    index = j;
                    break;
                }
            }

            // Step 2: Search right side of target
            int nextGreater = -1;
            for (int j = index + 1; j < nums2.size(); j++) {
                if (nums2[j] > target) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};
******************************************************************Better solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> indexMap;

        // Store index of each element in nums2
        for (int i = 0; i < nums2.size(); i++) {
            indexMap[nums2[i]] = i;
        }

        vector<int> ans;

        // Process every element in nums1
        for (int i = 0; i < nums1.size(); i++) {
            int target = nums1[i];

            // Directly get index from map
            int index = indexMap[target];

            int nextGreater = -1;

            // Search right side of target in nums2
            for (int j = index + 1; j < nums2.size(); j++) {
                if (nums2[j] > target) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};
******************************************************************Optimal Solution*********************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int current = nums2[i];

            // Remove all elements smaller than or equal to current
            // They cannot be next greater for current
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }

            // If stack is empty, no greater element exists on right side
            if (st.empty()) {
                nextGreater[current] = -1;
            } 
            else {
                // Stack top is the nearest greater element
                nextGreater[current] = st.top();
            }

            // Push current element for elements on the left side
            st.push(current);
        }

        vector<int> ans;

        // Build answer for nums1 using precomputed map
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(nextGreater[nums1[i]]);
        }

        return ans;
    }
};
