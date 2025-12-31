// find k closest points to origin (0,0) using a max-heap (priority queue)
// leetcode problem #973

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        // This vector will store the final answer
        vector<vector<int>> ans;

        // Edge case: if no points are given
        if (points.size() == 0)
            return ans;

        /*
            Max Heap (priority_queue):
            - Stores pairs of the form:
              {distance_from_origin, {x_coordinate, y_coordinate}}
            - The point with the maximum distance will be at the top
        */
        priority_queue<pair<int, pair<int, int>>> pq;

        // Iterate through all points
        for (int i = 0; i < points.size(); i++)
        {

            // Calculate squared Euclidean distance from origin
            // Using squared distance avoids costly sqrt operation
            int dist = points[i][0] * points[i][0] +
                       points[i][1] * points[i][1];

            // If heap size is less than k, push directly
            if (pq.size() < k)
            {
                pq.push({dist, {points[i][0], points[i][1]}});
            }
            else
            {
                /*
                    If current point is closer than the farthest
                    point in the heap, replace it
                */
                if (dist < pq.top().first)
                {
                    pq.pop();
                    pq.push({dist, {points[i][0], points[i][1]}});
                }
            }
        }

        // Extract k closest points from the heap
        while (!pq.empty())
        {
            ans.push_back({pq.top().second.first,
                           pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};
