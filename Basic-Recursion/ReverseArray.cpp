

# LeetCode 344. Reverse String

                                         ******************************************************************************
                                                         # Approach 1: Brute Force (Extra Array)
                                         ******************************************************************************

Intuition

// The simplest approach is to create another array.

// Traverse the original array from the end to the beginning.

// Store every character into the new array.

// Copy the new array back to the original array.

Algorithm

// 1. Create an empty temporary array.

// 2. Traverse from the last index to the first index.

// 3. Push every character into the temporary array.

// 4. Assign the temporary array back to the original array.

C++ Code

class Solution {
public:
    void reverseString(vector<char>& s) {

        vector<char> temp;

        for (int i = s.size() - 1; i >= 0; i--) {
            temp.push_back(s[i]);
        }

        s = temp;
    }
};

Time Complexity

// Traverse once.

// O(n)

Space Complexity

O(n)

Why is it Slow?

// Requires an extra array.

// Memory usage increases with input size.


---

                                         ******************************************************************************
                                                            # Approach 2: Better (Recursion)
                                         ******************************************************************************

Intuition

// Swap the first and last characters.

// Recursively reverse the remaining middle part.

// Continue until both pointers meet.

Algorithm

// 1. If left >= right, stop recursion.

// 2. Swap s[left] and s[right].

// 3. Recursively call for (left + 1, right - 1).

C++ Code

class Solution {
public:

    void solve(vector<char>& s, int left, int right) {

        if (left >= right)
            return;

        swap(s[left], s[right]);

        solve(s, left + 1, right - 1);
    }

    void reverseString(vector<char>& s) {

        solve(s, 0, s.size() - 1);
    }
};

Time Complexity

// Each element is visited once.

// O(n)

Space Complexity

O(n)

Why is it Better?

// No extra array is used.

// But recursion requires call stack memory.


---

                                         ******************************************************************************
                                                          # Approach 3: Optimal (Two Pointers)
                                         ******************************************************************************

Intuition

// Place one pointer at the beginning.

// Place another pointer at the end.

// Swap both characters.

// Move both pointers toward the center.

// Continue until they meet.

Algorithm

// 1. Initialize left = 0 and right = n - 1.

// 2. While left < right:

//    Swap s[left] and s[right].

//    Increment left.

//    Decrement right.

// 3. Return the modified array.

C++ Code

class Solution {
public:
    void reverseString(vector<char>& s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            swap(s[left], s[right]);

            left++;
            right--;
        }
    }
};

Time Complexity

// Traverse once.

// O(n)

Space Complexity

O(1)

Why is this Optimal?

// Every character is swapped at most once.

// No recursion.

// No extra array.

// Constant extra memory.


---

Complexity Comparison

Approach	Time Complexity	Space Complexity

Brute Force (Extra Array)	O(n)	O(n)
Better (Recursion)	O(n)	O(n)
Optimal (Two Pointers)	O(n)	O(1)
