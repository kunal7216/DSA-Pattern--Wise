# LeetCode 35. Search Insert Position

---

```text
                                         ******************************************************************************
                                                                # Approach 1: Brute Force
                                         ******************************************************************************
```

## Intuition

// The simplest approach is to traverse the array from left to right.

// For each element:

// 1. If the current element is equal to the target, return its index.

// 2. If the current element becomes greater than the target, the target should be inserted at this position.

// 3. If the traversal finishes, the target should be inserted at the end of the array.

// Since the array is sorted, this approach ignores the advantage of Binary Search.

---

## Algorithm

// 1. Traverse the array from left to right.

// 2. If `nums[i] >= target`, return `i`.

// 3. If no such element exists, return `nums.size()`.

---

## C++ Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] >= target)
                return i;
        }

        return nums.size();
    }
};
```

---

## Time Complexity

// Traverse all elements = **O(n)**

// Overall: **O(n)**

---

## Space Complexity

**O(1)**

---

## Why is it Slow?

// Every element may need to be checked.

// If

// * n = 10^5

// then the algorithm may scan the entire array before determining the insertion position.

---

```text
                                         ******************************************************************************
                                                          # Approach 2: Better (Binary Search)
                                         ******************************************************************************
```

## Intuition

// Since the array is sorted, we can eliminate half of the search space in every iteration.

// Keep track of the first index where the target can be placed.

// If `nums[mid] >= target`, store the answer and search the left half.

// Otherwise, search the right half.

---

## Algorithm

// 1. Initialize `low = 0`, `high = n - 1`, and `ans = n`.

// 2. Compute the middle index.

// 3. If `nums[mid] >= target`:

//    * Store `mid` as the possible answer.

//    * Continue searching on the left.

// 4. Otherwise search on the right.

// 5. Return `ans`.

---

## C++ Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
```

---

## Time Complexity

// Binary Search removes half of the search space in every iteration.

// Overall: **O(log n)**

---

## Space Complexity

**O(1)**

---

## Why is it Better?

// Instead of checking every element, Binary Search reduces the search space by half.

// This makes it much faster for large arrays.

---

```text
                                         ******************************************************************************
                                                     # Approach 3: Optimal (Lower Bound)
                                         ******************************************************************************
```

## Intuition

// The insertion position is exactly the **Lower Bound** of the target.

// Lower Bound returns the first index where

// `nums[index] >= target`.

// If the target exists, its index is returned.

// Otherwise, the correct insertion position is returned automatically.

---

## Algorithm

// 1. Use the STL function `lower_bound()`.

// 2. It returns an iterator to the first element that is greater than or equal to the target.

// 3. Convert the iterator into an index.

// 4. Return the index.

---

## C++ Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
```

---

## Time Complexity

// `lower_bound()` uses Binary Search.

// Overall: **O(log n)**

---

## Space Complexity

**O(1)**

---

## Why is this Optimal?

// * Uses the STL implementation of Binary Search.

// * Finds the answer in logarithmic time.

// * Uses constant extra memory.

// * No comparison-based algorithm can asymptotically perform better for this problem.

---

# Complexity Comparison

| Approach               | Time Complexity | Space Complexity |
| ---------------------- | --------------- | ---------------- |
| Brute Force            | **O(n)**        | **O(1)**         |
| Better (Binary Search) | **O(log n)**    | **O(1)**         |
| Optimal (Lower Bound)  | **O(log n)**    | **O(1)**         |
