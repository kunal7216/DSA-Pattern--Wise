# LeetCode 33. Search in Rotated Sorted Array

---

```
                                         ******************************************************************************
                                                                # Approach 1: Brute Force
                                         ******************************************************************************
```

## Intuition

// The simplest approach is to traverse the entire array one element at a time.

// For each element:

// 1. Check if it is equal to the target.
// 2. If yes, return its index immediately.
// 3. Otherwise continue searching.

// Since every element may need to be checked, this approach is straightforward but inefficient.

---

## Algorithm

// 1. Traverse the array from left to right.
// 2. Compare every element with the target.
// 3. If found, return its index.
// 4. If the traversal finishes without finding the target, return -1.

---

## C++ Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {

        // Traverse the entire array.
        for (int i = 0; i < nums.size(); i++) {

            // If target is found,
            // return its index.
            if (nums[i] == target)
                return i;
        }

        // Target does not exist.
        return -1;
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

// then in the worst case, every element must be checked before concluding that the target is absent.

---

```
                                         ******************************************************************************
                                                   # Approach 2: Binary Search by Finding Pivot
                                         ******************************************************************************
```

## Intuition

// A rotated sorted array consists of two sorted parts.

// First locate the pivot (smallest element).

// Once the pivot is known:

// * Decide which sorted half may contain the target.
// * Perform a normal Binary Search on that half.

// This avoids searching the entire array.

---

## Algorithm

// 1. Find the rotation index (pivot).
// 2. Check whether the target lies in the left or right sorted half.
// 3. Perform Binary Search on the selected half.
// 4. Return the index if found, otherwise return -1.

---

## C++ Code

```cpp
class Solution {
public:

    // Standard Binary Search
    int binarySearch(vector<int>& nums, int left, int right, int target) {

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int left = 0;
        int right = n - 1;

        // Find the pivot (minimum element).
        while (left < right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }

        int pivot = left;

        // Decide which sorted half contains the target.
        if (target >= nums[pivot] && target <= nums[n - 1])
            return binarySearch(nums, pivot, n - 1, target);

        return binarySearch(nums, 0, pivot - 1, target);
    }
};
```

---

## Time Complexity

// * Finding pivot = O(log n)

// * Binary Search = O(log n)

// Overall: **O(log n)**

---

## Space Complexity

**O(1)**

---

## Why is it Better?

// Instead of checking every element, we first identify the rotation point and then search only in the correct sorted half.

---

```
                                         ******************************************************************************
                                         # Approach 3: Optimal Binary Search (Without Finding Pivot)
                                         ******************************************************************************
```

## Intuition

// We do not need to explicitly find the pivot.

// Key observation:

// At every step of Binary Search, at least one half of the array is always sorted.

// We simply:

// * Identify the sorted half.
// * Check whether the target belongs to that half.
// * Discard the other half.

// This finishes the search in a single Binary Search.

---

## Algorithm

// 1. Initialize Binary Search.
// 2. Find the middle element.
// 3. If middle equals target, return its index.
// 4. Determine which half is sorted.
// 5. If target lies inside the sorted half, search there.
// 6. Otherwise search the opposite half.
// 7. Continue until the target is found or the search space becomes empty.

---

## C++ Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        // Perform Binary Search.
        while (left <= right) {

            int mid = left + (right - left) / 2;

            // Target found.
            if (nums[mid] == target)
                return mid;

            // Left half is sorted.
            if (nums[left] <= nums[mid]) {

                // Target lies inside left half.
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            // Right half is sorted.
            else {

                // Target lies inside right half.
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        // Target not found.
        return -1;
    }
};
```

---

## Time Complexity

// Binary Search performs approximately **log₂(n)** iterations.

// Overall: **O(log n)**

---

## Space Complexity

**O(1)**

---

## Why is this Optimal?

// * Every iteration eliminates half of the remaining search space.
// * The pivot does not need to be found separately.
// * Only one Binary Search is performed.
// * Therefore, O(log n) is the best possible time complexity for searching in a rotated sorted array.

---

# Complexity Comparison

| Approach              | Time Complexity | Space Complexity |
| --------------------- | --------------- | ---------------- |
| Brute Force           | **O(n)**        | **O(1)**         |
| Binary Search + Pivot | **O(log n)**    | **O(1)**         |
| Optimal Binary Search | **O(log n)**    | **O(1)**         |
