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


********************************************************************Brute Solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;

        // Check every index one by one
        for (int i = 0; i < n; i++) {
            int leftMax = 0;
            int rightMax = 0;

            // Find maximum height on the left side including current index
            for (int j = 0; j <= i; j++) {
                leftMax = max(leftMax, height[j]);
            }

            // Find maximum height on the right side including current index
            for (int j = i; j < n; j++) {
                rightMax = max(rightMax, height[j]);
            }

            // Water above current bar
            int waterAtIndex = min(leftMax, rightMax) - height[i];

            totalWater += waterAtIndex;
        }

        return totalWater;
    }
};
********************************************************************Better Solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n == 0) return 0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        // First element's left max is itself
        leftMax[0] = height[0];

        // Build leftMax array
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Last element's right max is itself
        rightMax[n - 1] = height[n - 1];

        // Build rightMax array
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int totalWater = 0;

        // Calculate trapped water at each index
        for (int i = 0; i < n; i++) {
            int waterAtIndex = min(leftMax[i], rightMax[i]) - height[i];
            totalWater += waterAtIndex;
        }

        return totalWater;
    }
};
********************************************************************Optimal SOlution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0;
        int right = n - 1;

        int leftMax = 0;
        int rightMax = 0;

        int totalWater = 0;

        while (left < right) {

            // If left height is smaller, left side decides water
            if (height[left] < height[right]) {

                // Update leftMax if current bar is taller
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } 
                else {
                    // Water can be trapped here
                    totalWater += leftMax - height[left];
                }

                left++;
            } 
            else {

                // Update rightMax if current bar is taller
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } 
                else {
                    // Water can be trapped here
                    totalWater += rightMax - height[right];
                }

                right--;
            }
        }

        return totalWater;
    }
};
