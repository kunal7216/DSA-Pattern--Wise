vector<int> previousSmallerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> s; // Stack to keep track of previous smaller elements

    for (int i = 0; i < n; i++) {
        // Pop elements from the stack until we find a smaller element or the stack is empty
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        // If the stack is empty, there is no smaller element to the left
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top(); // The top element is the previous smaller element
        }

        // Push the current element onto the stack
        s.push(arr[i]);
    }

    return result;
}

******************************************************************Brute solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {

            // Check next n - 1 elements circularly
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

        // Copy nums once
        for (int i = 0; i < n; i++) {
            doubled.push_back(nums[i]);
        }

        // Copy nums again to simulate circular array
        for (int i = 0; i < n; i++) {
            doubled.push_back(nums[i]);
        }

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {

            // Search next n - 1 positions
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

        // Traverse twice because array is circular
        for (int i = 2 * n - 1; i >= 0; i--) {

            int index = i % n;

            // Remove smaller or equal elements
            // They cannot be next greater
            while (!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }

            // Fill answer only during the real pass
            if (i < n) {
                if (!st.empty()) {
                    ans[index] = st.top();
                }
            }

            // Current element becomes a candidate for left-side elements
            st.push(nums[index]);
        }

        return ans;
    }
};
