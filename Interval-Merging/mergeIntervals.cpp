// merge intervals problem
// leetcode link: https://leetcode.com/problems/merge-intervals/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        // Result vector to store merged intervals
        vector<vector<int>> res;

        // Edge case: if no intervals are given, return empty result
        if (intervals.size() == 0)
        {
            return res;
        }

        // Step 1: Sort intervals based on starting time
        // This helps us merge overlapping intervals in a single pass
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        // Step 2: Initialize current interval with the first sorted interval
        vector<int> curr = intervals[0];

        // Step 3: Traverse remaining intervals
        for (int i = 1; i < intervals.size(); i++)
        {

            // If current interval ends before the next interval starts,
            // then there is no overlap
            if (curr[1] < intervals[i][0])
            {

                // Push the completed interval into result
                res.push_back(curr);

                // Move to the next interval
                curr = intervals[i];
            }
            else
            {
                // Overlapping case:
                // Merge intervals by extending the end time
                curr[1] = max(curr[1], intervals[i][1]);
            }
        }

        // Step 4: Push the last processed interval
        res.push_back(curr);

        // Return all merged intervals
        return res;
    }
};
