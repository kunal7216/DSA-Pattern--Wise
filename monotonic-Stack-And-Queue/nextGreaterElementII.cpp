// LeetCode 503: Next Greater Element II (Circular Array)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        // Initialize answer array with -1
        // Default value is -1 if no next greater element exists
        vector<int> ans(n, -1);

        // Stack stores indices of elements in nums
        // It will be maintained as a decreasing monotonic stack
        stack<int> s;

        // Traverse the array twice (2*n - 1 to 0)
        // This simulates the circular nature of the array
        for (int i = 2 * n - 1; i >= 0; i--) {

            // Remove elements from stack that are
            // smaller than or equal to the current element
            // because they cannot be the next greater element
            while (!s.empty() && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }

            // If stack is not empty, the top element is the
            // next greater element for nums[i % n]
            // If empty, it remains -1
            ans[i % n] = s.empty() ? -1 : nums[s.top()];

            // Push the current index (i % n) onto the stack
            // % n ensures index stays within bounds
            s.push(i % n);
        }

        // Return the result array
        return ans;
    }
};


******************************************************************Brute solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            
            for (int step = 1; step < n; step++) {
                
                int nextIndex = (i + step) % n;

                if (nums[nextIndex] > nums[i]) {
                    ans[i] = nums[nextIndex];
                    break;
                }
            }
        }

        return ans;
    }
};
******************************************************************Better solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> doubled;

        for (int i = 0; i < n; i++) {
            doubled.push_back(nums[i]);
        }

        for (int i = 0; i < n; i++) {
            doubled.push_back(nums[i]);
        }

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            
            for (int j = i + 1; j < i + n; j++) {
                
                if (doubled[j] > nums[i]) {
                    ans[i] = doubled[j];
                    break;
                }
            }
        }

        return ans;
    }
};
******************************************************************Optimal Solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);

        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            
            int index = i % n;

            while (!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }

            if (i < n) {
                if (!st.empty()) {
                    ans[index] = st.top();
                }
            }

            st.push(nums[index]);
        }

        return ans;
    }
};
