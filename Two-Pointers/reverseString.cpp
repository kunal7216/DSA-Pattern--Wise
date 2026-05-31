
***************************************************************************Brute solution**************************************************************************
  #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        // Temporary vector to store reversed characters
        vector<char> temp;

        // Traverse original array from end to start
        for (int i = n - 1; i >= 0; i--) {
            temp.push_back(s[i]);
        }

        // Copy reversed characters back into original array
        for (int i = 0; i < n; i++) {
            s[i] = temp[i];
        }
    }
};
****************************************************************************Better Solution*******************************************************************************
  #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<char>& s, int left, int right) {
        // Base condition: when pointers cross or meet
        if (left >= right) {
            return;
        }

        // Swap characters at left and right positions
        swap(s[left], s[right]);

        // Move towards the middle
        helper(s, left + 1, right - 1);
    }

    void reverseString(vector<char>& s) {
        int n = s.size();

        // Start recursion from first and last index
        helper(s, 0, n - 1);
    }
};
******************************************************************************Optimal solution******************************************************************************
  #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        // Continue until both pointers meet or cross
        while (left < right) {
            // Swap characters from both ends
            swap(s[left], s[right]);

            // Move left pointer forward
            left++;

            // Move right pointer backward
            right--;
        }
    }
};
