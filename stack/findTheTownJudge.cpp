                                                        ******************************************************
                                                        // LeetCode 997. Find the Town Judge
                                                        *******************************************************
                                                        // Approach 1: Brute Force


// The town judge must satisfy two conditions:

     // 1. The judge trusts nobody.
    // 2. Everyone else trusts the judge.

// For every person from `1` to `n`, assume they are the judge:
// - First, check whether they trust anyone. If they do, they cannot be the judge.
// - If they trust nobody, verify that every other person trusts them.
// - If both conditions are satisfied, return that person.
// - If no such person exists, return `-1`.

    
// Algorithm
// 1. Iterate through every person as a potential judge.
// 2. Scan the `trust` array to check whether the candidate trusts anyone.
// 3. If the candidate trusts someone, move to the next candidate.
// 4. Otherwise, check every other person to ensure they trust the candidate.
// 5. Return the candidate if both conditions are true.
// 6. If no candidate satisfies both conditions, return `-1`.


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        // Try every person as a possible judge
        for (int candidate = 1; candidate <= n; candidate++) {

            bool trustsSomeone = false;

            // Check if the candidate trusts anyone
            for (auto &edge : trust) {
                if (edge[0] == candidate) {
                    trustsSomeone = true;
                    break;
                }
            }

            // A judge cannot trust anyone
            if (trustsSomeone)
                continue;

            bool everyoneTrusts = true;

            // Check whether every other person trusts the candidate
            for (int person = 1; person <= n; person++) {

                if (person == candidate)
                    continue;

                bool found = false;

                // Search for an edge: person -> candidate
                for (auto &edge : trust) {
                    if (edge[0] == person && edge[1] == candidate) {
                        found = true;
                        break;
                    }
                }

                // If any person does not trust the candidate,
                // then the candidate cannot be the judge.
                if (!found) {
                    everyoneTrusts = false;
                    break;
                }
            }

            if (everyoneTrusts)
                return candidate;
        }

        return -1;
    }
};


 // Time Complexity
 //   - O(N × E)
 //   - `N` candidates × scanning up to `E` trust relationships repeatedly.

 // Space Complexity
 //   - **O(1)**

 // Bottleneck
 //     The same `trust` list is scanned multiple times, making the solution inefficient.

 // Why It Fails
 //     For large inputs (e.g., `N = 1000`, `E = 10000`), repeatedly traversing the entire trust list results in poor performance.


                                                            ***************************************************
                                                            //  Approach 2: Better (Adjacency Matrix)
                                                            **************************************************

// Improvement Over Brute Force
//      Instead of repeatedly scanning the `trust` array, store all trust relationships in an **adjacency matrix**.

//      This allows checking whether one person trusts another in **O(1)** time.

//  Intuition
// - Build a matrix where:
//   - `trustMatrix[a][b] = true` means person `a` trusts person `b`.
// - For every candidate:
//   - Ensure they trust nobody.
//   - Ensure everyone else trusts them.

//  Algorithm
// 1. Build the adjacency matrix.
// 2. Iterate through every person as a candidate.
// 3. Check that the candidate trusts nobody.
// 4. Check that every other person trusts the candidate.
// 5. Return the candidate if both conditions hold.
// 6. Otherwise return `-1`.


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        // trustMatrix[a][b] = true means person 'a' trusts person 'b'
        vector<vector<bool>> trustMatrix(n + 1, vector<bool>(n + 1, false));

        // Build adjacency matrix
        for (auto &edge : trust)
            trustMatrix[edge[0]][edge[1]] = true;

        // Try every person as the judge
        for (int candidate = 1; candidate <= n; candidate++) {

            bool trustsSomeone = false;

            // Judge should trust nobody
            for (int person = 1; person <= n; person++) {
                if (trustMatrix[candidate][person]) {
                    trustsSomeone = true;
                    break;
                }
            }

            if (trustsSomeone)
                continue;

            bool everyoneTrusts = true;

            // Everyone else should trust the judge
            for (int person = 1; person <= n; person++) {

                if (person == candidate)
                    continue;

                if (!trustMatrix[person][candidate]) {
                    everyoneTrusts = false;
                    break;
                }
            }

            if (everyoneTrusts)
                return candidate;
        }

        return -1;
    }
};


//  Time Complexity
// - O(N² + E)

//   Space Complexity
// - O(N²)

//  Why It Is Better
//       Trust checks become **O(1)** instead of scanning the entire trust list.

//  Why It Is Still Not Optimal
//        The adjacency matrix requires **O(N²)** memory, which is unnecessary for sparse graphs.

//  Limitation
//         For large values of `N`, memory consumption becomes the major issue.


                                            ******************************************************************
                                            // // Approach 3: Optimal (In-Degree & Out-Degree Counting)
                                            *******************************************************************
    
//  Key Insight
// Think of the problem as a directed graph.

// If `a` trusts `b`, then:

// - `outDegree[a]++`
// - `inDegree[b]++`

// The town judge must satisfy:

// - Out-degree = 0 (trusts nobody)
// - In-degree = N − 1 (trusted by everyone else)

// Beginner Intuition
// Instead of checking every person repeatedly:

// - Count how many people each person trusts.
// - Count how many people trust each person.
// - At the end, find the person whose:
//   - `outDegree = 0`
//   - `inDegree = n - 1`

// That person is the judge.

//  Algorithm
// 1. Create two arrays:
//    - `inDegree`
//    - `outDegree`
// 2. Traverse the trust list once.
// 3. Update both degree arrays.
// 4. Find the person satisfying:
//    - `outDegree == 0`
//    - `inDegree == n - 1`
// 5. Return that person, otherwise return `-1`.


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        // Number of people trusting each person
        vector<int> inDegree(n + 1, 0);

        // Number of people each person trusts
        vector<int> outDegree(n + 1, 0);

        // Build degree counts
        for (auto &edge : trust) {

            int a = edge[0];
            int b = edge[1];

            outDegree[a]++;
            inDegree[b]++;
        }

        // Find the judge
        for (int person = 1; person <= n; person++) {

            // Judge trusts nobody and is trusted by everyone else
            if (outDegree[person] == 0 &&
                inDegree[person] == n - 1)
                return person;
        }

        return -1;
    }
};

//  Time Complexity
// - O(N + E)

//  Space Complexity
// - O(N)

//  Why This Is Optimal
// - Every trust relationship is processed exactly once.
// - Every person is checked exactly once.
// - No unnecessary repeated scanning.
// - No extra quadratic memory.

// This is the most efficient solution possible because every trust relationship must be examined at least once.

