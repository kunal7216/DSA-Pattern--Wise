# LeetCode 34. Find First and Last Position of Element in Sorted Array

---

                                         ******************************************************************************
                                                                # Approach 1: Brute Force
                                         ******************************************************************************
```

## Intuition


// The simplest approach is to traverse the entire array one element at a time.
//
// While traversing:
//
// 1. If the current element equals the target:
//      - Store its index as the first occurrence if it hasn't been found yet.
//      - Keep updating the last occurrence.
//
// 2. Continue until the end of the array.
//
// Finally return {first, last}.
//
// If the target never appears,
// both values remain -1.
```

---

## Algorithm


// 1. Initialize first = -1 and last = -1.
// 2. Traverse the array.
// 3. If nums[i] == target:
//
//      * If first is still -1,
//        store i as first.
//
//      * Update last = i.
//
// 4. Return {first, last}.
```

---

## C++ Code


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = -1;
        int last = -1;

        // Traverse every element.
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == target) {

                // Store first occurrence.
                if (first == -1)
                    first = i;

                // Update last occurrence.
                last = i;
            }
        }

        return {first, last};
    }
};
```

---

## Time Complexity


// Traverse all elements = O(n)
//
// Overall: O(n)
```

---

// ## Space Complexity

```
// O(1)
```

---

// ## Why is it Slow?


// Even though the array is sorted,
// this approach ignores that property.
//
// If
//
// n = 10^5
//
// every element may still need to be checked.
//
// We can do much better using Binary Search.
```

---                                
                                         ******************************************************************************
                                                 # Approach 2: Binary Search using lower_bound() & upper_bound()
                                         ******************************************************************************
```

## Intuition


// Since the array is already sorted,
// Binary Search can be used instead of traversing the entire array.
//
// STL provides:
//
// * lower_bound() -> First position where target can be inserted.
// * upper_bound() -> First position greater than target.
//
// If target exists:
//
// First Occurrence = lower_bound
//
// Last Occurrence = upper_bound - 1
//
// Otherwise return {-1, -1}.
```

---

## Algorithm


// 1. Find the first occurrence using lower_bound().
// 2. If lower_bound points outside the array
//    or does not contain the target,
//    return {-1, -1}.
// 3. Find upper_bound().
// 4. Last occurrence = upper_bound - 1.
// 5. Return both indices.
```

---

## C++ Code


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        auto first = lower_bound(nums.begin(), nums.end(), target);

        // Target not present.
        if (first == nums.end() || *first != target)
            return {-1, -1};

        auto last = upper_bound(nums.begin(), nums.end(), target);

        return {
            (int)(first - nums.begin()),
            (int)(last - nums.begin()) - 1
        };
    }
};
```

---

## Time Complexity


// lower_bound() = O(log n)
//
// upper_bound() = O(log n)
//
// Overall:
//
// O(log n)
```

---

## Space Complexity

```
O(1)
```

---

## Why is it Better?


// Instead of checking every element,
// Binary Search repeatedly halves the search space.
//
// This reduces the complexity
// from O(n) to O(log n).
//
// Although this solution is optimal,
// interviewers often expect you to implement
// Binary Search manually instead of using STL.
```

---


                                         ******************************************************************************
                                                    # Approach 3: Optimal Manual Binary Search
                                         ******************************************************************************
```

## Intuition


// Since the array is sorted,
// Binary Search can efficiently find the target.
//
// Instead of stopping when the target is found:
//
// * Perform one Binary Search to find the first occurrence.
// * Perform another Binary Search to find the last occurrence.
//
// While searching:
//
// For the first occurrence:
// Continue searching towards the left.
//
// For the last occurrence:
// Continue searching towards the right.
//
// Finally return both indices.
```

---

## Algorithm

```cpp
// 1. Perform Binary Search to find the first occurrence.
//
//      * If target is found,
//        store the index.
//
//      * Continue searching in the left half.
//
// 2. Perform Binary Search again to find the last occurrence.
//
//      * If target is found,
//        store the index.
//
//      * Continue searching in the right half.
//
// 3. Return {first, last}.
```

---

## C++ Code


class Solution {
public:

    int firstOccurrence(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {

                ans = mid;

                // Continue searching on the left.
                right = mid - 1;
            }
            else if (nums[mid] < target) {

                left = mid + 1;
            }
            else {

                right = mid - 1;
            }
        }

        return ans;
    }

    int lastOccurrence(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {

                ans = mid;

                // Continue searching on the right.
                left = mid + 1;
            }
            else if (nums[mid] < target) {

                left = mid + 1;
            }
            else {

                right = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = firstOccurrence(nums, target);
        int last = lastOccurrence(nums, target);

        return {first, last};
    }
};
```

---

## Time Complexity

```cpp
// First Binary Search = O(log n)
//
// Second Binary Search = O(log n)
//
// Overall:
//
// O(log n)
```

---

## Space Complexity

```
O(1)
```

---

## Why is this Optimal?

```cpp
// Binary Search eliminates half of the
// remaining search space in every iteration.
//
// Two Binary Searches still take
// only O(log n) time.
//
// Since comparison-based searching
// on a sorted array cannot be faster
// than O(log n),
// this is the optimal solution.
```

---

# Complexity Comparison

| Approach                                              | Time Complexity | Space Complexity |
| ----------------------------------------------------- | --------------- | ---------------- |
| Brute Force                                           | **O(n)**        | **O(1)**         |
| Binary Search using `lower_bound()` & `upper_bound()` | **O(log n)**    | **O(1)**         |
| Optimal Manual Binary Search                          | **O(log n)**    | **O(1)**         |




