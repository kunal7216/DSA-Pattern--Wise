// using set to check for duplicates

/*
Explanation:

unordered_set keeps track of numbers we've seen.
If we encounter a number already in the set → return true.
If we finish the loop without returning → array has all unique numbers.

Time Complexity:
O(n) — each insert/find in unordered_set is O(1) on average.

Space Complexity:
O(n) — we store all unique numbers.
*/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // Step 1: Create an unordered_set to store unique numbers
        unordered_set<int> numSet;

        // Step 2: Traverse the array
        for (int n : nums)
        {
            // If number already exists in the set, duplicate found
            if (numSet.find(n) != numSet.end())
            {
                return true;
            }
            // Otherwise, insert number into the set
            numSet.insert(n);
        }

        // Step 3: No duplicates found
        return false;
    }
};



// using sorting to check for duplicates

/*
Explanation:

Sorting places duplicates next to each other.
Loop through the sorted array and check if any consecutive elements are equal.
If found → return true, otherwise → return false.

Time Complexity:
O(n log n) — due to sorting.

Space Complexity:
O(1) — or O(n) if sorting uses extra space (depends on language/library).
*/
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Check consecutive elements for duplicates
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                return true; // Duplicate found
            }
        }

        // Step 3: No duplicates found
        return false;
    }
};
