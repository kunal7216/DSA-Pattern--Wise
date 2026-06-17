// merge intervals problem
// leetcode link: https://leetcode.com/problems/merge-intervals/

*****************************************************Brute Solution*********************************************************************************
    class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        bool changed = true;

        while (changed) {
            changed = false;

            for (int i = 0; i < intervals.size(); i++) {

                for (int j = i + 1; j < intervals.size(); j++) {

                    if (max(intervals[i][0], intervals[j][0]) <=
                        min(intervals[i][1], intervals[j][1])) {

                        intervals[i][0] =
                            min(intervals[i][0], intervals[j][0]);

                        intervals[i][1] =
                            max(intervals[i][1], intervals[j][1]);

                        intervals.erase(intervals.begin() + j);

                        changed = true;
                        break;
                    }
                }

                if (changed) break;
            }
        }

        return intervals;
    }
};
*****************************************************Better Solution*********************************************************************************
    class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for (int i = 0; i < intervals.size(); i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            int j = i + 1;

            while (j < intervals.size() &&
                   intervals[j][0] <= end) {

                end = max(end, intervals[j][1]);
                j++;
            }

            result.push_back({start, end});

            i = j - 1;
        }

        return result;
    }
};
*****************************************************Optimal Solution*********************************************************************************
    class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            int lastEnd = merged.back()[1];

            if (currentStart <= lastEnd) {

                merged.back()[1] =
                    max(lastEnd, currentEnd);

            } else {

                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
