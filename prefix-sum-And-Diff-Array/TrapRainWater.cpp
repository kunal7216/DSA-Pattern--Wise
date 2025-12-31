class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        // Two pointers starting from both ends
        int left = 0, right = n - 1;

        // Stores the maximum height seen so far from left and right
        int leftMax = 0, rightMax = 0;

        // Variable to store total trapped rainwater
        int water = 0;

        // Process until both pointers meet
        while (left < right)
        {

            // Update maximum heights from both ends
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            // If left side is the smaller boundary
            if (leftMax < rightMax)
            {

                // Water trapped at current left index
                // = max height on left - current height
                water += leftMax - height[left];

                // Move left pointer forward
                left++;
            }
            else
            {
                // Right side is the smaller or equal boundary

                // Water trapped at current right index
                // = max height on right - current height
                water += rightMax - height[right];

                // Move right pointer backward
                right--;
            }
        }

        // Return total trapped rainwater
        return water;
    }
};
