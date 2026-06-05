class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        // Number of days
        int n = temperatures.size();

        // Result array initialized with 0
        // 0 means: no warmer day found in the future
        vector<int> res(n, 0);

        // Stack to store indices of days
        // This will be a MONOTONIC DECREASING STACK
        // (temperatures at stored indices are in decreasing order)
        stack<int> st;

        // Traverse temperatures from left to right
        for (int i = 0; i < n; i++)
        {

            // While stack is not empty and
            // current temperature is greater than
            // temperature at index stored on stack top
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {

                // Index at the top of stack
                int prevIndex = st.top();

                // Difference in days gives the answer
                res[prevIndex] = i - prevIndex;

                // Remove index since its next warmer day is found
                st.pop();
            }

            // Push current index onto stack
            // Waiting to find its next warmer day
            st.push(i);
        }

        // Remaining indices in stack have no warmer day ahead
        // Their result remains 0 (already initialized)
        return res;
    }
};


******************************************************************Brute solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        // Initially, all answers are 0
        vector<int> ans(n, 0);

        // Check each day
        for (int i = 0; i < n; i++) {

            // Check all future days
            for (int j = i + 1; j < n; j++) {

                // If future day is warmer
                if (temperatures[j] > temperatures[i]) {

                    // Number of days waited
                    ans[i] = j - i;

                    // First warmer day found, so stop
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        // Answer array initialized with 0
        vector<int> ans(n, 0);

        // Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {

            // Start from next day
            int j = i + 1;

            // Keep jumping in future
            while (j < n) {

                // If warmer day found
                if (temperatures[j] > temperatures[i]) {
                    ans[i] = j - i;
                    break;
                }

                // If j itself has no warmer future day,
                // then current i also cannot get answer through j
                if (ans[j] == 0) {
                    break;
                }

                // Jump to next warmer day of j
                j = j + ans[j];
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        // Answer array initialized with 0
        vector<int> ans(n, 0);

        // Stack stores indices of days
        // whose next warmer day is not found yet
        stack<int> st;

        // Traverse from left to right
        for (int i = 0; i < n; i++) {

            // If current day is warmer than previous pending days
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {

                // Previous unresolved day
                int prevIndex = st.top();
                st.pop();

                // Current day is the next warmer day
                ans[prevIndex] = i - prevIndex;
            }

            // Current day is now unresolved
            st.push(i);
        }

        return ans;
    }
};
    
