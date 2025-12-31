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
