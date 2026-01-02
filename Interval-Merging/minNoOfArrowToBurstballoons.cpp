// minimu no of arrows to burst balloons
//link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// Comparator function to sort balloons based on their ending point (x_end)
bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1]; // Sort by end coordinate
}

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {

        // Edge case: if no balloons are present
        if (points.size() == 0)
            return 0;

        // Step 1: Sort all balloons by their ending x-coordinate
        // This helps us place arrows optimally
        sort(points.begin(), points.end(), comp);

        // At least one arrow is needed for the first balloon
        int arrows = 1;

        // Store the end of the first balloon
        int end = points[0][1];

        // Step 2: Traverse remaining balloons
        for (int i = 1; i < points.size(); i++)
        {

            // If the current balloon starts after the last arrow position,
            // it means this balloon cannot be burst with the same arrow
            if (points[i][0] > end)
            {

                // Need a new arrow
                arrows++;

                // Update the end position to the current balloon's end
                end = points[i][1];
            }

            // Else:
            // The current balloon overlaps with the previous arrow range,
            // so it can be burst using the same arrow
        }

        // Return the minimum number of arrows needed
        return arrows;
    }
};
