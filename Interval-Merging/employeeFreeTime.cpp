// Employee freee time 
// leetcode problem link: https://leetcode.com/problems/employee-free-time/
// GFG problem link: https://practice.geeksforgeeks.org/problems/employee-free-time/1


//find the common free time slots of all employees given their working time slots

*********************************************************Brute Solution**********************************************************************************
    class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {

        int maxEnd = 0;

        for (auto &emp : schedule) {
            for (auto &it : emp) {
                maxEnd = max(maxEnd, it.end);
            }
        }

        vector<int> busy(maxEnd + 1, 0);

        for (auto &emp : schedule) {
            for (auto &it : emp) {
                for (int t = it.start; t < it.end; t++) {
                    busy[t] = 1;
                }
            }
        }

        vector<Interval> ans;

        int start = -1;

        for (int t = 0; t < maxEnd; t++) {

            if (!busy[t] && start == -1)
                start = t;

            if (busy[t] && start != -1) {
                ans.push_back(Interval(start, t));
                start = -1;
            }
        }

        return ans;
    }
};
*********************************************************Better Solution**********************************************************************************
    class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {

        vector<Interval> intervals;

        for (auto &emp : schedule) {
            for (auto &it : emp) {
                intervals.push_back(it);
            }
        }

        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });

        vector<Interval> merged;

        for (auto &cur : intervals) {

            if (merged.empty() ||
                merged.back().end < cur.start) {

                merged.push_back(cur);
            }
            else {
                merged.back().end =
                    max(merged.back().end, cur.end);
            }
        }

        vector<Interval> ans;

        for (int i = 1; i < merged.size(); i++) {

            ans.push_back(
                Interval(
                    merged[i - 1].end,
                    merged[i].start
                )
            );
        }

        return ans;
    }
};
*********************************************************Optimal Solution**********************************************************************************
    class Solution {
public:

    struct Node {
        int start;
        int end;
        int emp;
        int idx;
    };

    struct Compare {
        bool operator()(Node &a, Node &b) {
            return a.start > b.start;
        }
    };

    vector<Interval> employeeFreeTime(
        vector<vector<Interval>> schedule) {

        priority_queue<
            Node,
            vector<Node>,
            Compare
        > pq;

        int k = schedule.size();

        for (int i = 0; i < k; i++) {
            pq.push({
                schedule[i][0].start,
                schedule[i][0].end,
                i,
                0
            });
        }

        Node cur = pq.top();
        pq.pop();

        int prevEnd = cur.end;

        vector<Interval> ans;

        if (cur.idx + 1 < schedule[cur.emp].size()) {

            auto &next =
                schedule[cur.emp][cur.idx + 1];

            pq.push({
                next.start,
                next.end,
                cur.emp,
                cur.idx + 1
            });
        }

        while (!pq.empty()) {

            Node top = pq.top();
            pq.pop();

            if (top.start > prevEnd) {

                ans.push_back(
                    Interval(prevEnd, top.start)
                );

                prevEnd = top.end;
            }
            else {

                prevEnd =
                    max(prevEnd, top.end);
            }

            if (top.idx + 1 <
                schedule[top.emp].size()) {

                auto &next =
                    schedule[top.emp][top.idx + 1];

                pq.push({
                    next.start,
                    next.end,
                    top.emp,
                    top.idx + 1
                });
            }
        }

        return ans;
    }
};
