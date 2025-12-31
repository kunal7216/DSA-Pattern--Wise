// first missing positive number 
// Problem Link: https://leetcode.com/problems/first-missing-positive/
// this question is solved based on frequency count hashmap and set

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {

        // Map to store frequency of each number in the array
        map<int, int> mp;

        // Store all elements of nums into the map
        for (auto i : nums)
            mp[i]++;

        // The smallest missing positive must lie in range [1, n+1]
        // We check from 1 up to nums.size() + 1
        for (int i = 1; i <= nums.size() + 1; i++)
        {

            // If a number i is not present in the map,
            // then it is the first missing positive
            if (mp[i] == 0)
                return i;
        }

        // This line is technically redundant because
        // we will always return inside the loop
        return nums.size() + 1;
    }
};
