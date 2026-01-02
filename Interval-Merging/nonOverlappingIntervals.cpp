// non overlapping intervals
// link: https://practice.geeksforgeeks.org/problems/non-overlapping-intervals/

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        // This variable will store the minimum number of intervals
        // that need to be removed to make the remaining intervals non-overlapping
        int res = 0;

        // Sort intervals based on their end time
        // This greedy choice allows us to keep intervals
        // that finish earliest, leaving more room for others
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b)
             { return a[1] < b[1]; });

        // Store the end time of the first interval
        // This represents the last interval we decided to keep
        int prev_end = intervals[0][1];

        // Iterate through the remaining intervals
        for (int i = 1; i < intervals.size(); i++)
        {

            // If the current interval starts before the previous one ends,
            // it means there is an overlap
            if (prev_end > intervals[i][0])
            {

                // Since they overlap, we must remove one interval
                // We increment the removal count
                res++;
            }
            else
            {

                // If there is no overlap, we keep the current interval
                // and update prev_end to its end time
                prev_end = intervals[i][1];
            }
        }

        // Return the minimum number of intervals to remove
        return res;
    }
};
