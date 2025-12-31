class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Case 1: duplicates - cannot decide the sorted half
            if (arr[low] == arr[mid] && arr[mid] == arr[high])
            {
                ans = min(ans, arr[low]);
                low++;
                high--;
            }
            // Case 2: left part is sorted
            else if (arr[low] <= arr[mid])
            {
                ans = min(ans, arr[low]);
                low = mid + 1;
            }
            // Case 3: right part is sorted
            else
            {
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
