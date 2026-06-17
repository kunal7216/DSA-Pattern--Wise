// insert intervals
// leetcode link: https://leetcode.com/problems/insert-interval/

*****************************************************Brute Solution*********************************************************************************
    class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for (auto &interval : intervals) {

            if (result.empty() ||
                result.back()[1] < interval[0]) {

                result.push_back(interval);
            }
            else {
                result.back()[1] =
                    max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};
*****************************************************Better Solution*********************************************************************************
    class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> temp;

        bool inserted = false;

        for (auto &interval : intervals) {

            if (!inserted &&
                newInterval[0] < interval[0]) {

                temp.push_back(newInterval);
                inserted = true;
            }

            temp.push_back(interval);
        }

        if (!inserted)
            temp.push_back(newInterval);

        vector<vector<int>> result;

        for (auto &interval : temp) {

            if (result.empty() ||
                result.back()[1] < interval[0]) {

                result.push_back(interval);
            }
            else {

                result.back()[1] =
                    max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};
*****************************************************Optimal Solution*********************************************************************************
    class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> result;

        int i = 0;
        int n = intervals.size();

        // Phase 1:
        // Add intervals completely before newInterval

        while (i < n &&
               intervals[i][1] < newInterval[0]) {

            result.push_back(intervals[i]);
            i++;
        }

        // Phase 2:
        // Merge overlapping intervals

        while (i < n &&
               intervals[i][0] <= newInterval[1]) {

            newInterval[0] =
                min(newInterval[0], intervals[i][0]);

            newInterval[1] =
                max(newInterval[1], intervals[i][1]);

            i++;
        }

        result.push_back(newInterval);

        // Phase 3:
        // Add remaining intervals

        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
