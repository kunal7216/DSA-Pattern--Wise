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
