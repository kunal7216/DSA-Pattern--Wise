#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {

        // Minimum possible eating speed (1 banana per hour)
        int low = 1;

        // Maximum possible speed = largest pile of bananas
        int high = *max_element(piles.begin(), piles.end());

        // This will store the minimum valid eating speed
        int ans = high;

        // Binary search to find the minimum speed
        while (low <= high)
        {

            // Try the middle speed
            int mid = low + (high - low) / 2;

            // Total hours needed if Koko eats at speed = mid
            int hours = 0;

            // Calculate hours required for each pile
            for (int p : piles)
            {

                // (p + mid - 1) / mid is ceiling division
                // It tells how many hours this pile will take
                hours += (p + mid - 1) / mid;
            }

            // If Koko can finish within h hours
            if (hours <= h)
            {

                // Save this speed as a possible answer
                ans = mid;

                // Try to find a smaller valid speed
                high = mid - 1;
            }
            else
            {
                // Speed is too slow, increase it
                low = mid + 1;
            }
        }

        // Return the minimum eating speed that works
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << "Minimum eating speed: " << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}