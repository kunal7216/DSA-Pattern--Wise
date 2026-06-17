// minimu no of arrows to burst balloons
//link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// Comparator function to sort balloons based on their ending point (x_end)

*****************************************************Brute Solution*********************************************************************************
    class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        int n = points.size();
        vector<bool> burst(n, false);

        int arrows = 0;

        for(int i = 0; i < n; i++) {

            if(burst[i]) continue;

            arrows++;

            long long arrowPos = points[i][1];

            for(int j = i; j < n; j++) {

                if(!burst[j] &&
                   points[j][0] <= arrowPos &&
                   arrowPos <= points[j][1]) {

                    burst[j] = true;
                }
            }
        }

        return arrows;
    }
};
*****************************************************Better Solution*********************************************************************************
    class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        if(points.empty()) return 0;

        sort(points.begin(), points.end());

        int arrows = 1;

        long long overlapStart = points[0][0];
        long long overlapEnd = points[0][1];

        for(int i = 1; i < points.size(); i++) {

            if(points[i][0] <= overlapEnd) {

                overlapStart = max(overlapStart,
                                   (long long)points[i][0]);

                overlapEnd = min(overlapEnd,
                                 (long long)points[i][1]);
            }
            else {

                arrows++;

                overlapStart = points[i][0];
                overlapEnd = points[i][1];
            }
        }

        return arrows;
    }
};
*****************************************************Optimal Solution*********************************************************************************
    class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        if(points.empty()) return 0;

        sort(points.begin(), points.end(),
            [](const vector<int>& a,
               const vector<int>& b) {

                return a[1] < b[1];
            });

        int arrows = 1;

        long long arrowPos = points[0][1];

        for(int i = 1; i < points.size(); i++) {

            // Current arrow cannot burst this balloon
            if(points[i][0] > arrowPos) {

                arrows++;

                arrowPos = points[i][1];
            }
        }

        return arrows;
    }
};
