// remove duplicates from sorted array

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // If the array is empty, there are no elements to process
        if (nums.empty())
            return 0;

        // 'i' represents the position where the next unique element
        // should be placed. The first element is always unique.
        int i = 1;

        // 'j' is used to traverse the array from the second element onward
        for (int j = 1; j < nums.size(); j++)
        {

            // Compare current element with the previous unique element
            // (nums[i - 1] always holds the last unique value)
            if (nums[j] != nums[i - 1])
            {

                // Place the new unique element at index 'i'
                nums[i] = nums[j];

                // Move 'i' forward to the next position
                i++;
            }
        }

        // 'i' now represents the count of unique elements
        // The first 'i' elements in nums are the unique ones
        return i;
    }
};
