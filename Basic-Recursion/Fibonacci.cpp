LeetCode 509. Fibonacci Number


---

                                         ******************************************************************************
                                                                # Approach 1: Brute Force (Recursion)
                                         ******************************************************************************

Intuition

// The simplest approach is to directly follow the Fibonacci definition.

// For every Fibonacci number:

// 1. If n is 0, return 0.

// 2. If n is 1, return 1.

// 3. Otherwise, recursively calculate the previous two Fibonacci numbers.

// 4. Return their sum.

// This approach solves the same subproblems many times.

Algorithm

// 1. If n == 0, return 0.

// 2. If n == 1, return 1.

// 3. Return fib(n - 1) + fib(n - 2).

C++ Code

class Solution {
public:
    int fib(int n) {

        // Base cases
        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        // Recursive case
        return fib(n - 1) + fib(n - 2);
    }
};

Time Complexity

// Every call creates two more recursive calls.

// O(2ⁿ)

Space Complexity

O(n)

Why is it Slow?

// The same Fibonacci values are calculated repeatedly.

// Example:

// fib(5)

// ├── fib(4)

// │   ├── fib(3)

// │   └── fib(2)

// └── fib(3) ← calculated again

// This repeated work makes the solution exponential.


---

                                         ******************************************************************************
                                                             # Approach 2: Better (Memoization)
                                         ******************************************************************************

Intuition

// Store every Fibonacci value after computing it once.

// Whenever the same value is needed again,

// simply return the stored answer instead of recalculating it.

Algorithm

// 1. Create a DP array initialized with -1.

// 2. If n is 0 or 1, return n.

// 3. If dp[n] is already computed, return it.

// 4. Otherwise compute:

//    dp[n] = fib(n-1) + fib(n-2).

// 5. Return dp[n].

C++ Code

class Solution {
public:

    int solve(int n, vector<int>& dp) {

        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int fib(int n) {

        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};

Time Complexity

// Each state is computed only once.

// O(n)

Space Complexity

O(n)

Why is it Better?

// Repeated recursive calls are avoided.

// Every Fibonacci number is calculated only once.


---


                                         ******************************************************************************
                                                         # Approach 3: Optimal (Tabulation)
                                         ******************************************************************************

Intuition

// Instead of recursion,

// build Fibonacci numbers from the bottom.

// Since

// fib(i) = fib(i - 1) + fib(i - 2),

// we can iteratively compute every value until n.

Algorithm

// 1. If n <= 1, return n.

// 2. Create a DP array.

// 3. Initialize:

//    dp[0] = 0

//    dp[1] = 1

// 4. Traverse from 2 to n.

// 5. Compute:

//    dp[i] = dp[i-1] + dp[i-2].

// 6. Return dp[n].

C++ Code

class Solution {
public:
    int fib(int n) {

        if (n <= 1)
            return n;

        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};

Time Complexity

// Traverse once.

// O(n)

Space Complexity

O(n)

Why is this Optimal?

// Every Fibonacci number is computed exactly once.

// No repeated recursion.

// Linear time complexity is achieved.


---

                                         ******************************************************************************
                                                # Approach 4: Space Optimized (Best)
                                         ******************************************************************************

Intuition

// To compute the current Fibonacci number,

// we only need the previous two values.

// Therefore, instead of storing the entire DP array,

// keep only two variables.

Algorithm

// 1. If n <= 1, return n.

// 2. Initialize:

//    prev2 = 0

//    prev1 = 1

// 3. Traverse from 2 to n.

// 4. Compute current = prev1 + prev2.

// 5. Update the previous values.

// 6. Return prev1.

C++ Code

class Solution {
public:
    int fib(int n) {

        if (n <= 1)
            return n;

        int prev2 = 0;
        int prev1 = 1;

        for (int i = 2; i <= n; i++) {

            int curr = prev1 + prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

Time Complexity

// Traverse once.

// O(n)

Space Complexity

O(1)

Why is this Optimal?

// Every Fibonacci number is computed exactly once.

// Only two variables are used.

// No recursion.

// No extra DP array.

// This is the most space-efficient solution.


---

Complexity Comparison

Approach	Time Complexity	Space Complexity

Brute Force (Recursion)	O(2ⁿ)	O(n)
Better (Memoization)	O(n)	O(n)
Optimal (Tabulation)	O(n)	O(n)
Space Optimized (Best)	O(n)	O(1)
