// meeting rooms problem link: https://leetcode.com/problems/meeting-rooms/
//find mini rooms required to hold all meetings



int solution(vector<vector<int>> &intervals)
{
    // Sort intervals based on start time
    sort(intervals.begin(), intervals.end());

    // Min-heap to track the end times of meetings
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (const auto &interval : intervals)
    {
        // If the earliest ending meeting is done before the current meeting starts
        if (!minHeap.empty() && minHeap.top() <= interval[0])
        {
            minHeap.pop(); // Reuse the room
        }

        // Allocate a new room (or reuse) by adding the end time of the current meeting
        minHeap.push(interval[1]);
    }

    // The size of the heap is the number of rooms required
    return minHeap.size();
}