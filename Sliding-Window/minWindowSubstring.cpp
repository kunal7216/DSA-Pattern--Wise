class Solution
{
public:
    string minWindow(string s, string t)
    {

        // If s is smaller than t, it is impossible to find a valid window
        if (s.length() < t.length())
        {
            return "";
        }

        // Map to store the frequency of characters required from string t
        unordered_map<char, int> charCount;
        for (char ch : t)
        {
            charCount[ch]++; // Count each character in t
        }

        int targetCharsRemaining = t.length(); // Total characters still needed
        int minWindow[2] = {0, INT_MAX};       // Stores best window [start, end]
        int startIndex = 0;                    // Left pointer of sliding window

        // Right pointer expands the window
        for (int endIndex = 0; endIndex < s.length(); endIndex++)
        {
            char ch = s[endIndex];

            // If current character is required and still needed
            if (charCount.find(ch) != charCount.end() && charCount[ch] > 0)
            {
                targetCharsRemaining--; // One required character found
            }

            // Decrease count for current character (even if not required)
            charCount[ch]--;

            // When all characters of t are included in the current window
            if (targetCharsRemaining == 0)
            {

                // Try to shrink the window from the left
                while (true)
                {
                    char charAtStart = s[startIndex];

                    // Stop shrinking if removing this character
                    // would make the window invalid
                    if (charCount.find(charAtStart) != charCount.end() &&
                        charCount[charAtStart] == 0)
                    {
                        break;
                    }

                    // Otherwise, remove the character from window
                    charCount[charAtStart]++;
                    startIndex++;
                }

                // Update the minimum window if the current one is smaller
                if (endIndex - startIndex < minWindow[1] - minWindow[0])
                {
                    minWindow[0] = startIndex;
                    minWindow[1] = endIndex;
                }

                // Move left pointer forward to look for a new window
                charCount[s[startIndex]]++; // Put back the required character
                targetCharsRemaining++;     // One required character is now missing
                startIndex++;
            }
        }

        // If no valid window was found, return empty string
        return minWindow[1] >= s.length()
                   ? ""
                   : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
    }
};



****************************************************************Another Approach*************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Edge case: agar t empty hai ya t ka size s se bada hai,
        // toh valid window possible nahi hai.
        if (t.empty() || s.empty() || t.size() > s.size()) {
            return "";
        }

        // need[ch] = t string me character ch kitni baar chahiye
        // window[ch] = current sliding window me character ch kitni baar hai
        vector<int> need(128, 0);
        vector<int> window(128, 0);

        // t ki frequency store karo
        for (char ch : t) {
            need[ch]++;
        }

        // required = t me unique characters ki count
        // Example: t = "AABC"
        // need: A=2, B=1, C=1
        // required = 3
        int required = 0;

        for (int i = 0; i < 128; i++) {
            if (need[i] > 0) {
                required++;
            }
        }

        // formed = current window me kitne unique characters fully satisfy ho chuke hain
        // Example:
        // need[A] = 2
        // agar window[A] == 2, then A satisfied
        int formed = 0;

        // Sliding window ka left pointer
        int left = 0;

        // Answer track karne ke liye
        int minLen = INT_MAX;
        int startIndex = 0;

        // right pointer se window expand karenge
        for (int right = 0; right < s.size(); right++) {
            char rightChar = s[right];

            // Current character ko window me add karo
            window[rightChar]++;

            // Agar yeh character t me required hai
            // aur current window me exactly required frequency tak pahunch gaya hai,
            // then ek character type fully satisfied ho gaya
            if (need[rightChar] > 0 && window[rightChar] == need[rightChar]) {
                formed++;
            }

            // Jab tak current window valid hai,
            // tab tak left side se shrink karke minimum banane ki koshish karo
            while (left <= right && formed == required) {
                int currentLen = right - left + 1;

                // Agar current valid window ab tak ki smallest window hai,
                // toh answer update karo
                if (currentLen < minLen) {
                    minLen = currentLen;
                    startIndex = left;
                }

                char leftChar = s[left];

                // Shrink karne ke liye left character ko window se remove karo
                window[leftChar]--;

                // Agar removed character t me required tha
                // aur ab uski frequency required se kam ho gayi,
                // toh window invalid ho jayegi
                if (need[leftChar] > 0 && window[leftChar] < need[leftChar]) {
                    formed--;
                }

                // Left pointer ko aage badhao
                left++;
            }
        }

        // Agar koi valid window mili hi nahi
        if (minLen == INT_MAX) {
            return "";
        }

        // Minimum valid substring return karo
        return s.substr(startIndex, minLen);
    }
};
