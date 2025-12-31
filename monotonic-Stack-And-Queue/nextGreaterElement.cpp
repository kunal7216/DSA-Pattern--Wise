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
