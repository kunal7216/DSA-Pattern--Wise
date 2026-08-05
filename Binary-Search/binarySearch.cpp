# LeetCode 704. Binary Search

---


                                         ******************************************************************************
                                                                # Approach 1: Brute Force
                                         ******************************************************************************
```

## Intuition

// The simplest approach is to traverse the entire array one element at a time.

// For each element:

// 1. Compare it with the target.
// 2. If it matches, return its index.
// 3. Otherwise continue searching.

// Since the array is sorted, this approach ignores that property and checks every element.

---

## Algorithm

// 1. Traverse the array.
// 2. Compare every element with the target.
// 3. If found, return its index.
// 4. Otherwise return -1.

---

## C++ Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {

        // Check every element.
        for (int i = 0; i < nums.size(); i++) {

            // Target found.
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

// Even though the array is sorted, this approach still checks elements one by one.

// If

// * n = 10^5

// then in the worst case every element must be visited.

---


                                         ******************************************************************************
                                                     # Approach 2: Recursive Binary Search
                                         ******************************************************************************
```

## Intuition

// Since the array is sorted, we can repeatedly divide the search space into two halves.

// Compare the middle element with the target.

// * If equal, return its index.
// * If target is smaller, search the left half.
// * Otherwise search the right half.

---

## Algorithm

// 1. Find the middle element.
// 2. If middle equals target, return its index.
// 3. If target is smaller, recursively search the left half.
// 4. Otherwise recursively search the right half.
// 5. Return -1 if the search space becomes empty.

---

## C++ Code

```cpp
class Solution {
public:

    int binarySearch(vector<int>& nums, int left, int right, int target) {

        if (left > right)
            return -1;

        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;

        if (target < nums[mid])
            return binarySearch(nums, left, mid - 1, target);

        return binarySearch(nums, mid + 1, right, target);
    }

    int search(vector<int>& nums, int target) {

        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};
```

---

## Time Complexity

// Each recursive call removes half of the remaining search space.

// Overall: **O(log n)**

---

## Space Complexity

**O(log n)**

// Recursive call stack.

---

## Why is it Better?

// Instead of checking every element, Binary Search eliminates half of the search space after every comparison.

// However, recursion requires additional stack memory.

---


                                         ******************************************************************************
                                                      # Approach 3: Optimal Iterative Binary Search
                                         ******************************************************************************
```

## Intuition

// Since the array is already sorted, we can continuously eliminate half of the search space.

// Maintain two pointers:

// * left
// * right

// Find the middle element.

// * If it equals the target, return its index.
// * Otherwise discard one half of the array.

// Continue until the target is found or the search space becomes empty.

---

## Algorithm

// 1. Initialize left = 0 and right = n - 1.
// 2. Compute the middle index.
// 3. If nums[mid] == target, return mid.
// 4. If target is greater, search the right half.
// 5. Otherwise search the left half.
// 6. Return -1 if target is not found.

---

## C++ Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            // Target found.
            if (nums[mid] == target)
                return mid;

            // Search right half.
            if (nums[mid] < target)
                left = mid + 1;

            // Search left half.
            else
                right = mid - 1;
        }

        // Target does not exist.
        return -1;
    }
};
```

---

## Time Complexity

// Each iteration removes half of the remaining search space.

// Overall: **O(log n)**

---

## Space Complexity

**O(1)**

---

## Why is this Optimal?

// * Binary Search discards half of the search space after every comparison.

// * No extra memory is used.

// * Searching a sorted array faster than **O(log n)** using only comparisons is not possible.

---

# Complexity Comparison

| Approach                        | Time Complexity | Space Complexity |
| ------------------------------- | --------------- | ---------------- |
| Brute Force                     | **O(n)**        | **O(1)**         |
| Recursive Binary Search         | **O(log n)**    | **O(log n)**     |
| Optimal Iterative Binary Search | **O(log n)**    | **O(1)**         |
