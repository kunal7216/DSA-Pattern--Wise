// meeting room problem
// Given an array of meeting time intervals consisting of start and end times
// [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

// leetcode link: https://leetcode.com/problems/meeting-rooms/

*******************************************************Brute Solution*******************************************************************************
    class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int start1 = intervals[i][0];
                int end1   = intervals[i][1];

                int start2 = intervals[j][0];
                int end2   = intervals[j][1];

                if (max(start1, start2) < min(end1, end2))
                    return false;
            }
        }

        return true;
    }
};
*******************************************************Better Solution*******************************************************************************
    class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] < intervals[i - 1][1])
                return false;
        }

        return true;
    }
};
*******************************************************Optimal Solution*******************************************************************************
    class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {

            int previousEnd = intervals[i - 1][1];
            int currentStart = intervals[i][0];

            if (currentStart < previousEnd)
                return false;
        }

        return true;
    }
};
