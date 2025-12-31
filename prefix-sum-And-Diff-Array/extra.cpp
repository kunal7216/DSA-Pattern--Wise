// 1. Count Subarrays with some given condtion



//974. Count Subarray Sums Divisible by K
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i : nums)
        {
            sum = (sum + i) % k;
            if (sum < 0)
                sum = sum + k; // ADD k if sum negative to make it positive
            count += mp[sum];
            mp[sum]++;
        }
        return count;
    }
};

// 930. Count Binary Subarrays with given SUM

/*Given a binary array nums and an integer goal,
return the number of non-empty subarrays with a sum goal.*/
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        for (int it : nums)
        {
            sum += it;
            count += mp[sum - goal];
            mp[sum]++;
        }
        return count;
    }
};

// 2. Maximum length Subarray with given condition

// 525. Contiguous Array
/*Given a binary array nums, return the maximum length
of a subarray with an equal number of 0 and 1*/
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int one = 0, zero = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zero++;
            else
                one++;
            int diff = zero - one;
            if (mp.count(diff))
                ans = max(ans, i - mp[diff]);
            else
                mp[diff] = i;
        }
        return ans;
    }
};

// 325. Maximum Size Subarray Sum Equals k
// arguments of this code might differ
// from  leetcode version of this problem but
// the idea reamins same
int lenOfLongSubarr(int A[], int N, int K)
{
    // Stores the running (prefix) sum of elements
    int pre_sum = 0;

    // Stores the maximum length of subarray found so far
    int res = 0;

    // Hash map to store:
    // key   -> prefix sum
    // value -> first index where this prefix sum occurs
    unordered_map<int, int> mp;

    // Base case:
    // Prefix sum 0 occurs before the array starts (index -1)
    // Helps handle subarrays starting from index 0
    mp[0] = -1;

    // Traverse the array
    for (int i = 0; i < N; i++)
    {
        // Add current element to prefix sum
        pre_sum += A[i];

        // Check if (pre_sum - K) exists in the map
        // If yes, then subarray sum from
        // index (mp[pre_sum - K] + 1) to i equals K
        if (mp.find(pre_sum - K) != mp.end())
            res = max(res, i - mp[pre_sum - K]);

        // Store prefix sum only if it does not already exist
        // We store the FIRST occurrence to maximize subarray length
        if (mp.find(pre_sum) == mp.end())
            mp[pre_sum] = i;
    }

    // Return the length of the longest subarray with sum = K
    return res;
};

// 1658. Minimum Operations to Reduce X to Zero
/*given an integer array nums and an integer x.
In one operation, you can either remove the leftmost
or the rightmost element from the array nums
and subtract its value from x
Return the minimum number of operations
to reduce x to exactly 0 if it is possible, otherwise, return -1.*/
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    { // start
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int rem = total - x;
        if (rem == 0)
            return nums.size();

        int length = maxSubArrayLen(rem, nums);

        if (length == 0)
            return -1;
        return n - length;
    }

    int maxSubArrayLen(int k, vector<int> &A)
    { // Code for Maximum size subarray given sum
        int sum = 0;
        int res = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < A.size(); i++)
        {
            sum += A[i];
            if (mp.find(sum - k) != mp.end())
                res = max(res, i - mp[sum - k]);

            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return res;
    }
};

