class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {

        // Create a result array of same size as nums, initialized with 0
        vector<int> res(nums.size(), 0);

        // Left pointer starting from beginning of array
        int left = 0;

        // Right pointer starting from end of array
        int right = nums.size() - 1;

        // Traverse from the last index to the first index of result array
        // because we want to place the largest square first
        for (int i = nums.size() - 1; i >= 0; i--)
        {

            // Compare absolute values at left and right pointers
            if (abs(nums[left]) > abs(nums[right]))
            {

                // If left value has larger absolute value,
                // its square will be larger
                res[i] = nums[left] * nums[left];

                // Move left pointer forward
                left++;
            }
            else
            {

                // If right value has larger or equal absolute value,
                // its square will be larger
                res[i] = nums[right] * nums[right];

                // Move right pointer backward
                right--;
            }
        }

        // Return the sorted squares array
        return res;
    }
};

***********************************************************************Brute Solution********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;

        // Square every element
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(nums[i] * nums[i]);
        }

        // Sort the squared values
        sort(result.begin(), result.end());

        return result;
    }
};
****************************************************************************Better Solution***************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> negativeSquares;
        vector<int> positiveSquares;

        // Separate negative and non-negative square values
        for (int num : nums) {
            int square = num * num;

            if (num < 0) {
                negativeSquares.push_back(square);
            } else {
                positiveSquares.push_back(square);
            }
        }

        // Negative squares are in decreasing order,
        // so reverse them to make them increasing
        reverse(negativeSquares.begin(), negativeSquares.end());

        vector<int> result;

        int i = 0;
        int j = 0;

        // Merge two sorted arrays
        while (i < negativeSquares.size() && j < positiveSquares.size()) {
            if (negativeSquares[i] <= positiveSquares[j]) {
                result.push_back(negativeSquares[i]);
                i++;
            } else {
                result.push_back(positiveSquares[j]);
                j++;
            }
        }

        // Add remaining negative squares
        while (i < negativeSquares.size()) {
            result.push_back(negativeSquares[i]);
            i++;
        }

        // Add remaining positive squares
        while (j < positiveSquares.size()) {
            result.push_back(positiveSquares[j]);
            j++;
        }

        return result;
    }
};
    
********************************************************************************Optimal Solution***********************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);

        int left = 0;
        int right = n - 1;

        // Position to fill in result array
        int pos = n - 1;

        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            // Put the larger square at the current last position
            if (leftSquare > rightSquare) {
                result[pos] = leftSquare;
                left++;
            } else {
                result[pos] = rightSquare;
                right--;
            }

            pos--;
        }

        return result;
    }
};

