class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;          // Stores the maximum of each sliding window
        deque<int> dq;            // Deque to store indices of useful elements

        // Traverse through all elements of the array
        for (int i = 0; i < n; i++) {

            // Step 1: Remove indices that are out of the current window
            // If the front index is equal to (i - k), it means it is no longer
            // part of the current window of size k
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Step 2: Maintain decreasing order in deque
            // Remove all indices from the back whose corresponding values
            // are smaller than the current element nums[i],
            // because they can never be the maximum for any future window
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Step 3: Add the current index to the deque
            dq.push_back(i);

            // Step 4: Once the first window of size k is formed (i >= k - 1),
            // the element at the front of the deque is the maximum element
            // for the current window
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        // Return the list of maximums for all sliding windows
        return ans;
    }
};
