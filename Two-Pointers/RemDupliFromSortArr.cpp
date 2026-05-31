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

*************************************************************************Brute solution***********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> uniqueElements;

        // Edge case: if array is empty
        if (nums.size() == 0) {
            return 0;
        }

        // First element is always unique
        uniqueElements.push_back(nums[0]);

        // Start from second element
        for (int i = 1; i < nums.size(); i++) {
            // If current element is different from previous element,
            // then it is a new unique element
            if (nums[i] != nums[i - 1]) {
                uniqueElements.push_back(nums[i]);
            }
        }

        // Copy unique elements back into original nums array
        for (int i = 0; i < uniqueElements.size(); i++) {
            nums[i] = uniqueElements[i];
        }

        // Return number of unique elements
        return uniqueElements.size();
    }
};
****************************************************************************Better solution********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;

        // Insert all values into set
        // Set automatically removes duplicates
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        int index = 0;

        // Copy unique sorted values back into nums
        for (int value : st) {
            nums[index] = value;
            index++;
        }

        // Number of unique elements
        return index;
    }
};
******************************************************************************Optimal solution******************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge case: if array is empty
        if (nums.size() == 0) {
            return 0;
        }

        // i points to the last unique element's position
        int i = 0;

        // j scans from index 1 to end
        for (int j = 1; j < nums.size(); j++) {
            // If nums[j] is different from the last unique element,
            // then nums[j] is a new unique element
            if (nums[j] != nums[i]) {
                // Move unique pointer forward
                i++;

                // Place the new unique element at correct position
                nums[i] = nums[j];
            }
        }

        // Since i is index, count is i + 1
        return i + 1;
    }
};

