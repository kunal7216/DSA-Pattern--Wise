class Solution {
    public:
        bool isPalindrome(string s) {
    
            // Initialize two pointers:
            // 'start' begins from the left (start of string)
            // 'end' begins from the right (end of string)
            int start = 0;
            int end = s.size() - 1;
    
            // Loop until the two pointers cross each other
            while (start <= end) {
    
                // If the left character is NOT alphanumeric,
                // skip it and move the start pointer forward
                if (!isalnum(s[start])) {
                    start++;
                    continue;
                }
    
                // If the right character is NOT alphanumeric,
                // skip it and move the end pointer backward
                if (!isalnum(s[end])) {
                    end--;
                    continue;
                }
    
                // Compare characters after converting both to lowercase
                // This ensures case-insensitive comparison
                if (tolower(s[start]) != tolower(s[end]))
                    return false;   // Not a palindrome
    
                // Move both pointers towards the center
                start++;
                end--;
            }
    
            // If all valid characters matched, the string is a palindrome
            return true;
        }
    };
    