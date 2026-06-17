// non overlapping intervals
// link: https://practice.geeksforgeeks.org/problems/non-overlapping-intervals/

*****************************************************Brute Solution*********************************************************************************
    class Solution {
public:
    bool isValid(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());

        for(int i = 1; i < arr.size(); i++) {
            if(arr[i][0] < arr[i - 1][1])
                return false;
        }
        return true;
    }

    int ans = INT_MAX;

    void dfs(vector<vector<int>>& intervals,
             int idx,
             vector<vector<int>>& chosen,
             int removed) {

        if(idx == intervals.size()) {
            if(isValid(chosen))
                ans = min(ans, removed);
            return;
        }

        // Keep interval
        chosen.push_back(intervals[idx]);
        dfs(intervals, idx + 1, chosen, removed);
        chosen.pop_back();

        // Remove interval
        dfs(intervals, idx + 1, chosen, removed + 1);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> chosen;
        dfs(intervals, 0, chosen, 0);
        return ans;
    }
};
*****************************************************Better Solution*********************************************************************************
    class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        vector<int> dp(n, 1);

        int keep = 1;

        for(int i = 1; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(intervals[j][1] <= intervals[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            keep = max(keep, dp[i]);
        }

        return n - keep;
    }
};
*****************************************************Optimal Solution*********************************************************************************
    class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int removed = 0;

        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i][0] >= prevEnd) {
                // keep interval
                prevEnd = intervals[i][1];
            }
            else {
                // overlap
                removed++;
            }
        }

        return removed;
    }
};
