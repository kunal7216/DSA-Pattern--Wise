// leetcode 34 

// code for first and last occurences  of a number in a array
class Solution
{
public:
    // This function returns the first and last position of target in nums
    vector<int> searchRange(vector<int> &nums, int target)
    {

        // Default answer if target is not found
        vector<int> result = {-1, -1};

        // Find the first occurrence of target
        int left = binarySearch(nums, target, true);

        // Find the last occurrence of target
        int right = binarySearch(nums, target, false);

        // Store results
        result[0] = left;
        result[1] = right;

        return result;
    }

    // Modified binary search
    // isSearchingLeft = true  -> find first occurrence
    // isSearchingLeft = false -> find last occurrence
    int binarySearch(vector<int> &nums, int target, bool isSearchingLeft)
    {

        int left = 0;                // start pointer
        int right = nums.size() - 1; // end pointer
        int idx = -1;                // stores index of target if found

        // Standard binary search loop
        while (left <= right)
        {

            // Find middle index
            int mid = left + (right - left) / 2;

            // If middle element is greater than target,
            // search in the left half
            if (nums[mid] > target)
            {
                right = mid - 1;
            }

            // If middle element is smaller than target,
            // search in the right half
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }

            // If target is found
            else
            {
                idx = mid; // save current index

                // If searching for first occurrence,
                // continue searching on the left side
                if (isSearchingLeft)
                {
                    right = mid - 1;
                }
                // If searching for last occurrence,
                // continue searching on the right side
                else
                {
                    left = mid + 1;
                }
            }
        }

        // Return the index of first or last occurrence
        return idx;
    }
};
