************************************************************
                 // Approach 1: Brute Force
************************************************************
// Check every person as a potential celebrity.

// For each candidate:

//    * They should **not know anyone else.
//    * Everyone else** should know them.

// If both conditions are satisfied, return that candidate.


// Time Complexity: O(n²)
 // Space Complexity: O(1)

class Solution {
public:
    int findCelebrity(int n) {

        // Try every person as a possible celebrity
        for (int candidate = 0; candidate < n; candidate++) {

            bool isCelebrity = true;

            // Check all other people
            for (int person = 0; person < n; person++) {

                if (candidate == person)
                    continue;

                // Celebrity should not know anyone
                if (knows(candidate, person)) {
                    isCelebrity = false;
                    break;
                }

                // Everyone should know the celebrity
                if (!knows(person, candidate)) {
                    isCelebrity = false;
                    break;
                }
            }

            // Found the celebrity
            if (isCelebrity)
                return candidate;
        }

        // No celebrity exists
        return -1;
    }
};



************************************************************
            // Approach 2: Better (In-degree & Out-degree)
************************************************************

     // Treat every person as a graph node.
     // If `i` knows `j`:

           // * Increase out-degree of `i`.
          // * Increase in-degree of `j`.

     // A celebrity has:

         //  In-degree = `n - 1`
         //  Out-degree = `0`




      // Time Complexity: O(n²)
     // Space Complexity: O(n)

class Solution {
public:
    int findCelebrity(int n) {

        // Store how many people know each person
        vector<int> indegree(n, 0);

        // Store how many people each person knows
        vector<int> outdegree(n, 0);

        // Build indegree and outdegree arrays
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (i == j)
                    continue;

                if (knows(i, j)) {
                    outdegree[i]++;
                    indegree[j]++;
                }
            }
        }

        // Celebrity conditions
        for (int i = 0; i < n; i++) {

            if (indegree[i] == n - 1 &&
                outdegree[i] == 0)
                return i;
        }

        return -1;
    }
};



************************************************************
          // Approach 3: Stack (Candidate Elimination)
************************************************************

// Push all people into a stack.
// Compare the top two:

      // If `A` knows `B`, then `A` cannot be the celebrity.
      // Otherwise, `B` cannot be the celebrity.

// Push the possible candidate back.
// At the end, verify the remaining person.


// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int findCelebrity(int n) {

        stack<int> st;

        // Push all people into the stack
        for (int i = 0; i < n; i++)
            st.push(i);

        // Eliminate non-celebrities
        while (st.size() > 1) {

            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            // If a knows b, a cannot be celebrity
            if (knows(a, b))
                st.push(b);
            else
                st.push(a);
        }

        int candidate = st.top();

        // Verify candidate
        for (int i = 0; i < n; i++) {

            if (i == candidate)
                continue;

            // Candidate should know nobody
            if (knows(candidate, i))
                return -1;

            // Everyone should know candidate
            if (!knows(i, candidate))
                return -1;
        }

        return candidate;
    }
};

********************************************************
          // Approach 4: Optimal (Candidate Elimination)
********************************************************
    
// Keep only one candidate.
// For every person:
     // If candidate knows that person, candidate cannot be the celebrity.
     // Replace the candidate.

// Finally, verify the remaining candidate.


// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findCelebrity(int n) {

        // Assume first person is celebrity
        int candidate = 0;

        // Eliminate impossible candidates
        for (int i = 1; i < n; i++) {

            // Candidate knows i,
            // so candidate cannot be celebrity
            if (knows(candidate, i))
                candidate = i;
        }

        // Verify the remaining candidate
        for (int i = 0; i < n; i++) {

            if (i == candidate)
                continue;

            // Celebrity should know nobody
            if (knows(candidate, i))
                return -1;

            // Everyone should know celebrity
            if (!knows(i, candidate))
                return -1;
        }

        // Candidate is the celebrity
        return candidate;
    }
};

