# LeetCode 81. Search in Rotated Sorted Array II

---

```
                                         ******************************************************************************
                                                                # Approach 1: Brute Force
                                         ******************************************************************************
```

## Intuition

// The simplest approach is to traverse the entire array one element at a time.

// For each element:

// 1. Compare it with the target.
// 2. If it matches, return true.
// 3. Otherwise continue searching.

// Since duplicates may exist, this approach still works correctly but is inefficient.

---

## Algorithm

// 1. Traverse the array.
// 2. Compare every element with the target.
// 3. If found, return true.
// 4. Otherwise return false.

---

## C++ Code

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {

        // Check every element.
        for (int num : nums) {

            // Target found.
            if (num == target)
                return true;
        }

        // Target does not exist.
        return false;
    }
};
```

---

## Time Complexity

// * Traverse all elements = O(n)

// Overall: **O(n)**

---

## Space Complexity

**O(1)**

---

## Why is it Slow?

// If

// * n = 10^5

// then in the worst case every element must be checked.

---

```
                                         ******************************************************************************
                                                   # Approach 2: Binary Search by Finding Pivot
                                         ******************************************************************************
```

## Intuition

// First find the pivot (minimum element).

// Since duplicates exist, finding the pivot becomes slightly harder.

// Once the pivot is found:

// * Decide which sorted half may contain the target.
// * Perform Binary Search on that half.

---

## Algorithm

// 1. Find the pivot while handling duplicates.
// 2. Decide which half may contain the target.
// 3. Apply Binary Search.
// 4. Return true if found.

---

## C++ Code

```cpp
class Solution {
public:

    bool binarySearch(vector<int>& nums, int left, int right, int target) {

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }

    bool search(vector<int>& nums, int target) {

        int n = nums.size();

        int left = 0;
        int right = n - 1;

        // Find pivot while handling duplicates.
        while (left < right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {

                left = mid + 1;
            }
            else if (nums[mid] < nums[right]) {

                right = mid;
            }
            else {

                // Duplicate element.
                right--;
            }
        }

        int pivot = left;

        if (target >= nums[pivot] && target <= nums[n - 1])
            return binarySearch(nums, pivot, n - 1, target);

        return binarySearch(nums, 0, pivot - 1, target);
    }
};
```

---

## Time Complexity

// * Finding pivot = O(log n) average, O(n) worst case because of duplicates.

// * Binary Search = O(log n)

// Overall:

// **Average:** O(log n)

// **Worst:** O(n)

---

## Space Complexity

**O(1)**

---

## Why is it Better?

// Binary Search greatly reduces the search space in most cases.

// However, duplicates sometimes prevent us from determining which side is sorted, forcing us to shrink the search space one element at a time.

---

```
                                         ******************************************************************************
                                         # Approach 3: Optimal Modified Binary Search
                                         ******************************************************************************
```

## Intuition

// Unlike LeetCode 33, duplicates make it impossible to always determine which half is sorted.

// Example:

// [1,1,1,3,1]

// Here,

// nums[left] == nums[mid] == nums[right]

// We cannot identify the sorted half.

// So we simply shrink both ends by one position.

// Otherwise, perform the same Binary Search logic as LeetCode 33.

---

## Algorithm

// 1. Perform Binary Search.
// 2. If target equals middle element, return true.
// 3. If left, middle and right are equal:

//    * Increment left.
//    * Decrement right.
// 4. Otherwise identify the sorted half.
// 5. Search in the appropriate half.
// 6. Return false if target is not found.

---

## C++ Code

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            // Target found.
            if (nums[mid] == target)
                return true;

            // Cannot determine sorted half because of duplicates.
            if (nums[left] == nums[mid] &&
                nums[mid] == nums[right]) {

                left++;
                right--;
            }

            // Left half is sorted.
            else if (nums[left] <= nums[mid]) {

                if (target >= nums[left] &&
                    target < nums[mid]) {

                    right = mid - 1;
                }
                else {

                    left = mid + 1;
                }
            }

            // Right half is sorted.
            else {

                if (target > nums[mid] &&
                    target <= nums[right]) {

                    left = mid + 1;
                }
                else {

                    right = mid - 1;
                }
            }
        }

        return false;
    }
};
```

---

## Time Complexity

// **Average:** O(log n)

// **Worst:** O(n)

// Worst case occurs when the array contains many duplicate values (for example, `[1,1,1,1,1,1,1]`), forcing us to shrink the search space one element at a time.

---

## Space Complexity

**O(1)**

---

## Why is this Optimal?

// * Binary Search is still used whenever possible.
// * Duplicates are handled by shrinking both boundaries when the sorted half cannot be identified.
// * In the worst case, duplicates make O(log n) impossible, so O(n) is the best achievable complexity.

---

# Complexity Comparison

| Approach                       | Time Complexity                        | Space Complexity |
| ------------------------------ | -------------------------------------- | ---------------- |
| Brute Force                    | **O(n)**                               | **O(1)**         |
| Binary Search + Pivot          | **Average:** O(log n), **Worst:** O(n) | **O(1)**         |
| Optimal Modified Binary Search | **Average:** O(log n), **Worst:** O(n) | **O(1)**         |
