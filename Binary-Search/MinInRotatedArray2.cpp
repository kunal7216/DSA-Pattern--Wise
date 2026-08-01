# LeetCode 154. Find Minimum in Rotated Sorted Array II

---

```
                                         ******************************************************************************
                                                                # Approach 1: Brute Force
                                         ******************************************************************************
```

## Intuition

// The simplest approach is to scan the entire array and keep track of the smallest element.
// Since duplicates are allowed, we cannot directly take advantage of the sorted order.
// Therefore, checking every element guarantees the correct answer.

---

## Algorithm

// 1. Assume the first element is the minimum.
// 2. Traverse the entire array.
// 3. Update the minimum whenever a smaller element is found.
// 4. Return the minimum element.

---

## C++ Code

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {

        // Assume first element is the minimum.
        int minimum = nums[0];

        // Traverse every element.
        for (int num : nums) {

            // Update minimum.
            minimum = min(minimum, num);
        }

        // Return smallest element.
        return minimum;
    }
};
```

---

## Time Complexity

// * Traverse the array once = O(n)
// Overall: O(n)

---

## Space Complexity  O(1)

---

## Why is it Slow?

// This approach ignores the partially sorted nature of the array.
// Even if the answer is near the beginning, every element is still visited.

---

```
                                         ******************************************************************************
                                                   # Approach 2: Linear Search for Rotation Point
                                         ******************************************************************************
```

## Intuition

// The minimum element is located where the sorted order breaks.

// Example:

// 2 2 2 0 1 2
//       ^

// Here, 0 is smaller than its previous element.
// If no such position exists, the array is already sorted (or contains all equal elements), so the first element is the minimum.

---

## Algorithm

// 1. Traverse from index 1.
// 2. Compare nums[i] with nums[i-1].
// 3. If nums[i] < nums[i-1], return nums[i].
// 4. Otherwise return nums[0].

---

## C++ Code

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();

        // Find where sorted order breaks.
        for (int i = 1; i < n; i++) {

            if (nums[i] < nums[i - 1])
                return nums[i];
        }

        // Array is already sorted.
        return nums[0];
    }
};
```

---

## Time Complexity

// * Traverse once = O(n)
// Overall: O(n)

---

## Space Complexity

O(1)

---

## Why is it Better?

// This approach returns immediately after finding the rotation point.
// However, if the array is already sorted or contains many duplicates,
// it still scans the entire array.

---

```
                                         ******************************************************************************
                                         # Approach 3: Optimal Binary Search (Handles Duplicates)
                                         ******************************************************************************
```

## Intuition

// This problem is similar to LeetCode 153, but duplicates introduce ambiguity.

// Normally:

// * nums[mid] > nums[right] → minimum is in the right half.
// * nums[mid] < nums[right] → minimum is in the left half.

// However, when:
// nums[mid] == nums[right]

// we cannot determine which half contains the minimum because both halves may contain identical values.

// Therefore, we safely discard one duplicate by doing:
// right--

// This gradually removes duplicates while preserving the minimum.

---

## Algorithm

// 1. Initialize:

//    * left = 0
//    * right = n - 1

// 2. While left < right:

//    * Find mid.
//    * If nums[mid] > nums[right]:
//            Search right half.

//    * Else if nums[mid] < nums[right]:
//         Search left half including mid.

//    * Else:
//         right--

// 3. Continue until left == right.

// 4. Return nums[left].

---

## C++ Code

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        // Binary Search.
        while (left < right) {

            int mid = left + (right - left) / 2;

            // Minimum lies in the right half.
            if (nums[mid] > nums[right]) {

                left = mid + 1;
            }
            // Minimum lies in the left half (including mid).
            else if (nums[mid] < nums[right]) {

                right = mid;
            }
            // Cannot determine the correct half because of duplicates.
            else {

                // Safely remove one duplicate.
                right--;
            }
        }

        // left == right points to the minimum.
        return nums[left];
    }
};
```

---

## Time Complexity

// **Best / Average Case:** O(log n)
// Binary Search eliminates half of the search space.

// **Worst Case:** O(n)

// When the array contains many duplicates (e.g. [1,1,1,1,1]),
// we repeatedly execute `right--`, reducing the search space by only one element at a time.

---

## Space Complexity

O(1)

---

## Why is this Optimal?

// * Binary Search is still used whenever comparisons are informative.
// * Duplicates make it impossible to always eliminate half of the search space.
// * In the worst case, every element may need to be examined.
// * Therefore:

//   * Average Case = O(log n)
//   * Worst Case = O(n)

// This is the optimal solution for arrays containing duplicates.

---

# Complexity Comparison

| Approach                           | Time Complexity                    | Space Complexity |
| ---------------------------------- | ---------------------------------- | ---------------- |
| Brute Force                        | O(n)                               | O(1)             |
| Linear Search for Rotation Point   | O(n)                               | O(1)             |
| Binary Search (Handles Duplicates) | **Average: O(log n), Worst: O(n)** | **O(1)**         |
