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
