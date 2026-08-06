# Factorial Numbers Less Than or Equal to N


---

                                         ******************************************************************************
                                                               # Approach 1: Brute Force
                                         ******************************************************************************

Intuition

// The simplest approach is to compute the factorial of every number starting from 1.

// For each number:

// 1. Call a recursive factorial function. // 2. Print the factorial. // 3. Repeat until N.

// Since factorial is recomputed for every number, many recursive calls are repeated.

Algorithm

// 1. Read N.

// 2. For every number from 1 to N:

//    - Call factorial(i).

//    - Print the result.

// 3. The recursive function returns:

//    factorial(n) = n × factorial(n − 1).

C++ Code

class Solution {
public:
    long long factorial(int n) {

        // Base case
        if (n == 0 || n == 1)
            return 1;

        // Recursive case
        return 1LL * n * factorial(n - 1);
    }

    void factorialNumbers(int N) {

        for (int i = 1; i <= N; i++)
            cout << factorial(i) << " ";
    }
};

Time Complexity

// factorial(1) + factorial(2) + ... + factorial(N)

// O(1 + 2 + ... + N) = O(N²)

Space Complexity

O(N) (Recursive call stack)

Why is it Slow?

// Every factorial is computed from scratch.

// Example:

// factorial(5) again computes factorial(4), factorial(3), factorial(2)...

// These repeated recursive calls make the solution quadratic.


---

                                        ******************************************************************************
                                                           # Approach 2: Better (Iterative)
                                         ******************************************************************************

Intuition

// Instead of recomputing factorial every time,

// use the previous factorial.

// Since

// factorial(i) = factorial(i − 1) × i

// we can continuously update the answer.

Algorithm

// 1. Initialize fact = 1.

// 2. Traverse from 1 to N.

// 3. Multiply fact by the current number.

// 4. Print fact.

C++ Code

class Solution {
public:
    void factorialNumbers(int N) {

        long long fact = 1;

        for (int i = 1; i <= N; i++) {
            fact *= i;
            cout << fact << " ";
        }
    }
};

Time Complexity

// Traverse once = O(N)

Space Complexity

O(1)

Why is it Better?

// Every factorial is built using the previous one.

// No repeated calculations are performed.

// Only one traversal is required.


---

                                         ******************************************************************************
                                                       # Approach 3: Optimal (Recursive Build)
                                         ******************************************************************************

Intuition

// We can recursively generate factorials in increasing order.

// Pass the current factorial as a parameter.

// At every recursive call:

// 1. Print the current factorial.

// 2. Compute the next factorial.

// 3. Recurse for the next number.

// Thus every factorial is computed exactly once.

Algorithm

// 1. Start recursion with number = 1 and factorial = 1.

// 2. Print the current factorial.

// 3. Call recursion with:

//    number + 1

//    factorial × (number + 1)

// 4. Stop when number > N.

C++ Code

class Solution {
public:
    void solve(int i, int N, long long fact) {

        if (i > N)
            return;

        cout << fact << " ";

        solve(i + 1, N, fact * (i + 1));
    }

    void factorialNumbers(int N) {

        solve(1, N, 1);
    }
};

Time Complexity

// Every number is processed once.

// O(N)

Space Complexity

O(N) (Recursive call stack)

Why is this Optimal?

// Every factorial is computed exactly once.

// No repeated recursion.

// Recursive solution with linear time.

// Faster than the brute-force recursive approach while maintaining recursion.


---

Complexity Comparison

Approach	Time Complexity	Space Complexity

Brute Force (Recursive for every number)	O(N²)	O(N)
Better (Iterative)	O(N)	O(1)
Optimal (Recursive Build)	O(N)	O(N)
