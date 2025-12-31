// kth largest element in an array
// leetcode problem link: https://leetcode.com/problems/kth-largest-element-in-an-array/\


// using min heap

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        // Min-heap to store the k largest elements seen so far
        priority_queue<int, vector<int>, greater<int>> minpq;

        // Traverse all elements in the array
        for (int i = 0; i < nums.size(); i++)
        {

            // If heap size is less than k, push the element
            if (minpq.size() < k)
            {
                minpq.push(nums[i]);
            }
            else
            {
                // If current element is larger than the smallest
                // element in the heap, replace it
                if (minpq.top() < nums[i])
                {
                    minpq.pop();
                    minpq.push(nums[i]);
                }
            }
        }

        // The top of the min-heap is the kth largest element
        return minpq.top();
    }
};
