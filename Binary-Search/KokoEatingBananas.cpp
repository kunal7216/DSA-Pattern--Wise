#  LeetCode 875. Koko Eating Bananas

---

# Approach 1: Brute Force

## Intuition

The simplest approach is to try every possible eating speed from **1** to the size of the largest pile.

For each speed:

1. Calculate how many hours Koko needs to finish all piles.
2. If the total hours are less than or equal to `h`, then this is the minimum valid speed, so return it.

Since we check every possible speed, this approach is straightforward but very inefficient when the largest pile is very large.

---

## Algorithm

1. Find the maximum pile size.
2. Iterate speed from `1` to `maxPile`.
3. For every speed:

   * Calculate total hours using ceiling division.
4. Return the first speed that satisfies the condition.

---

## C++ Code

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // Find the largest pile because Koko never needs
        // to eat faster than the largest pile.
        int maxPile = *max_element(piles.begin(), piles.end());

        // Try every possible eating speed.
        for (int speed = 1; speed <= maxPile; speed++) {

            long long totalHours = 0;

            // Calculate total hours required at current speed.
            for (int bananas : piles) {

                // Ceiling division:
                // Example:
                // 7 bananas, speed = 3
                // Hours = ceil(7/3) = 3
                totalHours += (bananas + speed - 1) / speed;
            }

            // If Koko can finish within h hours,
            // this is the minimum possible speed.
            if (totalHours <= h)
                return speed;
        }

        return maxPile;
    }
};
```

---

## Time Complexity

* Finding maximum pile = **O(n)**
* Trying every speed = **O(maxPile)**
* For every speed, traverse all piles = **O(n)**

Overall:

**O(n × maxPile)**

---

## Space Complexity

**O(1)**

---

## Why is it Slow?

If

* `maxPile = 10^9`
* `n = 10^4`

then the algorithm performs nearly

`10^9 × 10^4 = 10^13`

operations, which is impossible within time limits.

---

# Approach 2: Binary Search with Helper Function

## Intuition

Notice an important observation:

* If Koko can finish at speed **k**, she can also finish at any speed greater than **k**.
* If she cannot finish at speed **k**, then every smaller speed also fails.

This monotonic property allows Binary Search.

Instead of checking every speed, we search only the valid range.

A helper function checks whether a given speed is sufficient.

---

## Algorithm

1. Set

   * `low = 1`
   * `high = maximum pile`
2. Find middle speed.
3. Check whether Koko can finish.
4. If yes:

   * Store answer.
   * Search smaller speeds.
5. Otherwise:

   * Search larger speeds.

---

## C++ Code

```cpp
class Solution {
public:

    // Returns true if Koko can finish within h hours.
    bool canFinish(vector<int>& piles, int h, int speed) {

        long long totalHours = 0;

        for (int bananas : piles) {

            // Ceiling division
            totalHours += (bananas + speed - 1) / speed;
        }

        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int answer = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Check if current speed works.
            if (canFinish(piles, h, mid)) {

                // Save answer.
                answer = mid;

                // Try to minimize speed.
                high = mid - 1;
            }
            else {

                // Need higher speed.
                low = mid + 1;
            }
        }

        return answer;
    }
};
```

---

## Time Complexity

Binary Search performs

**log(maxPile)**

iterations.

Each iteration scans all piles.

Overall:

**O(n × log(maxPile))**

---

## Space Complexity

**O(1)**

---

## Why is it Better?

Instead of checking every speed, Binary Search reduces the search space by half after every iteration.

---

# Approach 3: Optimal Binary Search (Without Extra Answer Variable)

## Intuition

This is the cleanest Binary Search implementation.

Instead of storing an answer separately, we continuously shrink the search space until both pointers meet.

The final pointer itself represents the minimum valid speed.

This version is shorter, cleaner, and is the most commonly used in interviews.

---

## Algorithm

1. Search between

   * `1`
   * `maximum pile`
2. Find middle speed.
3. Calculate required hours.
4. If Koko can finish:

   * Move right boundary to mid.
5. Otherwise:

   * Move left boundary to mid + 1.
6. Continue until both pointers become equal.

---

## C++ Code

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // Lowest possible speed.
        int left = 1;

        // Highest possible speed.
        int right = *max_element(piles.begin(), piles.end());

        // Binary Search on the answer.
        while (left < right) {

            int mid = left + (right - left) / 2;

            long long totalHours = 0;

            // Calculate total hours required
            // if Koko eats at speed = mid.
            for (int bananas : piles) {

                totalHours += (bananas + mid - 1) / mid;
            }

            // Current speed works.
            if (totalHours <= h) {

                // Try to find an even smaller speed.
                right = mid;
            }
            else {

                // Current speed is too slow.
                left = mid + 1;
            }
        }

        // left == right
        // Minimum possible eating speed.
        return left;
    }
};
```

---

## Time Complexity

Binary Search performs approximately

**log₂(maxPile)**

iterations.

Each iteration scans all piles.

Overall:

**O(n × log(maxPile))**

---

## Space Complexity

**O(1)**

---

## Why is this Optimal?

* Binary Search reduces the search space exponentially.
* Every feasibility check requires scanning all piles, so **O(n)** work per iteration is unavoidable.
* Therefore, **O(n × log(maxPile))** is the optimal time complexity for this problem.

---

# Complexity Comparison

| Approach                        | Time Complexity         | Space Complexity |
| ------------------------------- | ----------------------- | ---------------- |
| Brute Force                     | **O(n × maxPile)**      | **O(1)**         |
| Binary Search + Helper Function | **O(n × log(maxPile))** | **O(1)**         |
| Optimal Binary Search           | **O(n × log(maxPile))** | **O(1)**         |
