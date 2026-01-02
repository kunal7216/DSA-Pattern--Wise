// meeting room problem
// Given an array of meeting time intervals consisting of start and end times
// [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

// leetcode link: https://leetcode.com/problems/meeting-rooms/

class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>> &intervals)
    {

        // If there are 0 or 1 meetings, no overlap is possible
        if (intervals.size() <= 1)
            return true;

        // Sort all meetings based on start time
        // This arranges meetings in chronological order
        sort(intervals.begin(), intervals.end());

        // Iterate from the second meeting onward
        for (int i = 1; i < intervals.size(); i++)
        {

            // intervals[i][0]     -> start time of current meeting
            // intervals[i - 1][1] -> end time of previous meeting
            //
            // If current meeting starts before the previous one ends,
            // it means the two meetings overlap
            if (intervals[i][0] < intervals[i - 1][1])
            {

                // Overlap detected, cannot attend all meetings
                return false;
            }
        }

        // No overlapping meetings found
        return true;
    }
};
