// Employee freee time 
// leetcode problem link: https://leetcode.com/problems/employee-free-time/
// GFG problem link: https://practice.geeksforgeeks.org/problems/employee-free-time/1


//find the common free time slots of all employees given their working time slots

#include <bits/stdc++.h>
using namespace std;

/**
 * Interval structure used by LeetCode
 */
struct Interval
{
    int start;
    int end;

    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> &schedule)
    {

        // This will store all common free time intervals
        vector<Interval> result;

        // Min-heap (priority queue) that sorts intervals by start time
        // We want the interval with the smallest start time on top
        priority_queue<Interval, vector<Interval>,
                       function<bool(const Interval &, const Interval &)>>
            pq(
                [](const Interval &a, const Interval &b)
                {
                    return a.start > b.start; // min-heap based on start time
                });

        // Push all intervals of all employees into the priority queue
        // This flattens the 2D schedule into a single sorted stream
        for (auto &employee : schedule)
        {
            for (auto &interval : employee)
            {
                pq.push(interval);
            }
        }

        // Take the earliest interval as the previous interval
        Interval prev = pq.top();
        pq.pop();

        // Process all remaining intervals
        while (!pq.empty())
        {

            // Get the next interval in sorted order
            Interval curr = pq.top();
            pq.pop();

            // Case 1: There is a gap between previous and current interval
            // This gap is common free time for all employees
            if (prev.end < curr.start)
            {

                // Add the free time interval
                result.push_back(Interval(prev.end, curr.start));

                // Move previous pointer to current interval
                prev = curr;
            }
            // Case 2: Intervals overlap or touch
            else
            {
                // Merge intervals by extending the end time
                prev.end = max(prev.end, curr.end);
            }
        }

        // Return all common free time intervals
        return result;
    }
};

/*
Approach (Point-wise)

Flatten all schedules
Collect every working interval of all employees into a single data structure so they can be processed together.

Sort using a min-heap (priority queue)
Use a priority queue ordered by interval start time to always process the earliest starting interval first.

Initialize a reference interval (prev)
Pop the first interval from the priority queue and treat it as the currently merged working interval.

Process remaining intervals one by one
Repeatedly extract the next interval (curr) from the priority queue.

Check for free time (gap detection)

If prev.end < curr.start, a gap exists.

This gap represents common free time for all employees.

Add [prev.end, curr.start] to the result.

Merge overlapping intervals

If intervals overlap or touch, extend the current working interval.

Update prev.end = max(prev.end, curr.end).

Continue until all intervals are processed
Maintain merged busy intervals and record all gaps.

Return the result
The collected gaps are the common free time intervals.*/