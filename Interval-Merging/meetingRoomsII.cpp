// meeting rooms problem link: https://leetcode.com/problems/meeting-rooms/
//find mini rooms required to hold all meetings

***************************************************Brute Solution***********************************************************************************
    class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<int> rooms;

        for (auto& meeting : intervals) {

            int start = meeting[0];
            int end = meeting[1];

            bool placed = false;

            for (int i = 0; i < rooms.size(); i++) {

                if (rooms[i] <= start) {
                    rooms[i] = end;
                    placed = true;
                    break;
                }
            }

            if (!placed)
                rooms.push_back(end);
        }

        return rooms.size();
    }
};
***************************************************Better Solution***********************************************************************************
    class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<int> starts(n);
        vector<int> ends(n);

        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0;
        int endPtr = 0;

        for (int startPtr = 0; startPtr < n; startPtr++) {

            if (starts[startPtr] < ends[endPtr]) {
                rooms++;
            } else {
                endPtr++;
            }
        }

        return rooms;
    }
};
***************************************************Optimal Solution***********************************************************************************

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end());

        priority_queue<
            int,
            vector<int>,
            greater<int>
        > minHeap;

        minHeap.push(intervals[0][1]);

        for (int i = 1; i < intervals.size(); i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            if (minHeap.top() <= start) {
                minHeap.pop();
            }

            minHeap.push(end);
        }

        return minHeap.size();
    }
};
