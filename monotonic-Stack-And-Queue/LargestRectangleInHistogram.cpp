// C++ solution for "Largest Rectangle in Histogram"
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // left[i]  -> index of the nearest smaller element to the LEFT of i
        // right[i] -> index of the nearest smaller element to the RIGHT of i
        vector<int> left(n), right(n);

        // Stack will store indices of histogram bars
        stack<int> st;

        // --------- Nearest Smaller to Left (NSL) ---------
        for (int i = 0; i < n; i++) {

            // Pop elements from stack while the current bar
            // is smaller or equal than the bar at stack top
            // (we want strictly smaller element)
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            // If stack is empty, no smaller element on the left
            // so we use -1 as a boundary
            left[i] = st.empty() ? -1 : st.top();

            // Push current index to stack
            st.push(i);
        }

        // Clear stack before reusing it
        while (!st.empty())
            st.pop();

        // --------- Nearest Smaller to Right (NSR) ---------
        for (int i = n - 1; i >= 0; i--) {

            // Pop elements while current bar is smaller or equal
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            // If stack is empty, no smaller element on the right
            // so we use n as a boundary
            right[i] = st.empty() ? n : st.top();

            // Push current index
            st.push(i);
        }

        int maxArea = 0;

        // --------- Calculate Maximum Area ---------
        for (int i = 0; i < n; i++) {

            // Width of rectangle with height heights[i]
            // = distance between nearest smaller elements
            int width = right[i] - left[i] - 1;

            // Area = height * width
            int area = heights[i] * width;

            // Update maximum area
            maxArea = max(maxArea, area);
        }

        // Return the largest rectangle area
        return maxArea;
    }
};

******************************************************************Brute solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        // Try every starting index
        for (int i = 0; i < n; i++) {

            // Try every ending index
            for (int j = i; j < n; j++) {

                // Find minimum height between i and j
                int minHeight = INT_MAX;

                for (int k = i; k <= j; k++) {
                    minHeight = min(minHeight, heights[k]);
                }

                // Width of rectangle from i to j
                int width = j - i + 1;

                // Area using minimum height
                int area = minHeight * width;

                // Update answer
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
******************************************************************Better solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        // Fix starting index
        for (int i = 0; i < n; i++) {

            // Minimum height from i to j
            int minHeight = INT_MAX;

            // Extend ending index
            for (int j = i; j < n; j++) {

                // Update minimum height in current range
                minHeight = min(minHeight, heights[j]);

                // Width from i to j
                int width = j - i + 1;

                // Area of rectangle
                int area = minHeight * width;

                // Store maximum answer
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
******************************************************************Optimal Solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Stack stores indices of bars
        stack<int> st;

        int maxArea = 0;

        // We go till n inclusive to process remaining bars
        for (int i = 0; i <= n; i++) {

            // For i == n, we use height 0 to empty the stack
            int currentHeight = (i == n) ? 0 : heights[i];

            // If current bar is smaller, then stack top bar's rectangle ends here
            while (!st.empty() && currentHeight < heights[st.top()]) {

                // Height of rectangle
                int height = heights[st.top()];
                st.pop();

                // Right boundary is i
                int rightSmaller = i;

                // Left boundary is stack top after popping
                int leftSmaller;

                if (st.empty()) {
                    leftSmaller = -1;
                } else {
                    leftSmaller = st.top();
                }

                // Width where current height can extend
                int width = rightSmaller - leftSmaller - 1;

                // Calculate area
                int area = height * width;

                // Update answer
                maxArea = max(maxArea, area);
            }

            // Push current index
            st.push(i);
        }

        return maxArea;
    }
};
