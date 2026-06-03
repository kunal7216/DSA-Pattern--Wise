class NumArray
{
public:
    vector<int> &presum;
    // Reference to a vector that will store prefix sums.
    // Each index i stores the sum of elements from 0 to i.

    NumArray(vector<int> &nums) : presum(nums)
    {
        // Constructor initializes 'presum' as a reference to 'nums'
        // This avoids creating a new array and uses the same memory.

        for (int i = 1; i < presum.size(); i++)
            // Build the prefix sum array
            // Add previous sum to current element
            presum[i] += presum[i - 1];
    }

    int sumRange(int left, int right)
    {
        // Returns the sum of elements between indices left and right (inclusive)

        if (left == 0)
            // If the range starts from index 0,
            // the sum is directly the prefix sum at 'right'
            return presum[right];

        // Otherwise, subtract prefix sum before 'left'
        // This removes the sum of elements [0, left-1]
        return presum[right] - presum[left - 1];
    }
};

**************************************************************************Brute Solution********************************************************************************
    class NumArray {
private:
    vector<int> nums;

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;

        // Add all elements from left to right
        for (int i = left; i <= right; i++) {
            sum += nums[i];
        }

        return sum;
    }
};
***************************************************************************Better Solution*******************************************************************************
    class NumArray {
private:
    vector<vector<int>> rangeSum;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();

        rangeSum.resize(n, vector<int>(n, 0));

        // Precompute sum for every possible range
        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];
                rangeSum[i][j] = sum;
            }
        }
    }
    
    int sumRange(int left, int right) {
        return rangeSum[left][right];
    }
};
****************************************************************************Optimal Solution******************************************************************************
    class NumArray {
private:
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();

        // prefix[0] = 0
        // prefix[i + 1] stores sum from nums[0] to nums[i]
        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // Sum from left to right
        return prefix[right + 1] - prefix[left];
    }
};
