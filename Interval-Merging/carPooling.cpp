// car pooling 
// leetcode problem link: https://leetcode.com/problems/car-pooling/

*****************************************************Brute Solution*********************************************************************************
    class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> road(1001, 0);

        for (auto& trip : trips) {
            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            for (int i = from; i < to; i++) {
                road[i] += passengers;

                if (road[i] > capacity)
                    return false;
            }
        }

        return true;
    }
};
*****************************************************Better Solution*********************************************************************************
    class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<pair<int,int>> events;

        for (auto &trip : trips) {
            events.push_back({trip[1], trip[0]});   // pickup
            events.push_back({trip[2], -trip[0]});  // drop
        }

        sort(events.begin(), events.end());

        int passengers = 0;

        for (auto &event : events) {
            passengers += event.second;

            if (passengers > capacity)
                return false;
        }

        return true;
    }
};
*****************************************************Optimal Solution*********************************************************************************
    class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int> diff(1001, 0);

        for (auto &trip : trips) {

            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            diff[from] += passengers;
            diff[to] -= passengers;
        }

        int currentPassengers = 0;

        for (int i = 0; i < 1001; i++) {

            currentPassengers += diff[i];

            if (currentPassengers > capacity)
                return false;
        }

        return true;
    }
};
