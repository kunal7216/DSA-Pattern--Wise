******************************************************************Brute solution*********************************************************************************
  class Solution {
public:
    int findCelebrity(int n) {
        for (int i = 0; i < n; i++) {
            bool isCelebrity = true;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                // Celebrity should not know anyone
                if (knows(i, j)) {
                    isCelebrity = false;
                    break;
                }

                // Everyone should know celebrity
                if (!knows(j, i)) {
                    isCelebrity = false;
                    break;
                }
            }

            if (isCelebrity) {
                return i;
            }
        }

        return -1;
    }
};
******************************************************************Better solution*********************************************************************************
#include <stack>
using namespace std;

class Solution {
public:
    int findCelebrity(int n) {
        stack<int> st;

        // Push all people
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Eliminate non-celebrities
        while (st.size() > 1) {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if (knows(a, b)) {
                // a knows b, so a cannot be celebrity
                st.push(b);
            } else {
                // a does not know b, so b cannot be celebrity
                st.push(a);
            }
        }

        int candidate = st.top();

        // Verify candidate
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;

            // Candidate should know nobody
            if (knows(candidate, i)) {
                return -1;
            }

            // Everyone should know candidate
            if (!knows(i, candidate)) {
                return -1;
            }
        }

        return candidate;
    }
};
******************************************************************Optimal Solution*********************************************************************************
class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;

        // Step 1: Find possible celebrity
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i)) {
                // candidate knows i, so candidate cannot be celebrity
                candidate = i;
            }
        }

        // Step 2: Verify candidate
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;

            // Celebrity knows nobody
            if (knows(candidate, i)) {
                return -1;
            }

            // Everyone knows celebrity
            if (!knows(i, candidate)) {
                return -1;
            }
        }

        return candidate;
    }
};
