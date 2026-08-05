# LeetCode 162. Peak Element

---


                                         ******************************************************************************
                                                                # Approach 1: Brute Force
                                         ******************************************************************************
```

## Intuition

// The simplest approach is to check every element one by one.

// For each element:

// 1. Check if it is greater than its left neighbor.
// 2. Check if it is greater than its right neighbor.
// 3. If both conditions are true, it is a peak element.

// Since every element may need to be checked, this approach ignores the possibility of using Binary Search.

---

## Algorithm

// 1. Traverse the array.
// 2. For every index, verify whether it is greater than both neighbors.
// 3. Handle the boundary elements separately.
// 4. Return the index of the first peak found.

---

## C++ Code


class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        for (int i = 0; i < n; i++) {

            bool left = (i == 0 || nums[i] > nums[i - 1]);
            bool right = (i == n - 1 || nums[i] > nums[i + 1]);

            if (left && right)
                return i;
        }

        return -1;
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

// then the algorithm may examine every element before finding a peak.

---


                                         ******************************************************************************
                                                          # Approach 2: Better (Maximum Element)
                                         ******************************************************************************
```

## Intuition

// The maximum element in the array is always a peak.

// Therefore,

// 1. Traverse the array.
// 2. Find the largest element.
// 3. Return its index.

---

## Algorithm

// 1. Initialize the maximum index as 0.
// 2. Traverse the array.
// 3. Update the maximum index whenever a larger element is found.
// 4. Return the maximum index.

---

## C++ Code

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int maxIndex = 0;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        return maxIndex;
    }
};
```

---

## Time Complexity

// Traverse the entire array once = **O(n)**

// Overall: **O(n)**

---

## Space Complexity

**O(1)**

---

## Why is it Better?

// We no longer compare every element with both neighbors.

// Instead, we simply find the largest element.

// However, the entire array still needs to be traversed.

---


                                         ******************************************************************************
                                                     # Approach 3: Optimal Binary Search
                                         ******************************************************************************
```

## Intuition

// We do not need the maximum element.

// We only need any peak element.

// Compare the middle element with its next element.

// * If nums[mid] < nums[mid + 1], we are moving uphill, so a peak must exist on the right side.

// * Otherwise, we are moving downhill (or already at a peak), so a peak must exist on the left side including mid.

// Repeating this process continuously halves the search space.

---

## Algorithm

// 1. Initialize left = 0 and right = n - 1.
// 2. Find the middle index.
// 3. If nums[mid] < nums[mid + 1], search the right half.
// 4. Otherwise search the left half including mid.
// 5. Continue until left == right.
// 6. Return left as the peak index.

---

## C++ Code

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            // Peak lies on the right side.
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;

            // Peak lies on the left side (including mid).
            else
                right = mid;
        }

        return left;
    }
};
```

---

## Time Complexity

// Every iteration removes half of the remaining search space.

// Overall: **O(log n)**

---

## Space Complexity

**O(1)**

---

## Why is this Optimal?

// * At every step, Binary Search discards half of the search space.

// * No extra memory is used.

// * The required **O(log n)** complexity is achieved.

// * Searching faster than **O(log n)** using comparisons is not possible for this problem.

---

# Complexity Comparison

| Approach                 | Time Complexity | Space Complexity |
| ------------------------ | --------------- | ---------------- |
| Brute Force              | **O(n)**        | **O(1)**         |
| Better (Maximum Element) | **O(n)**        | **O(1)**         |
| Optimal Binary Search    | **O(log n)**    | **O(1)**         |
