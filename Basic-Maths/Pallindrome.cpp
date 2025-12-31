class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) return false;   // negative → not palindrome
    
            int rev = 0;
            int num = x;
    
            while (x != 0) {
                int digit = x % 10;
    
                // Overflow check
                if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
                    return false;
                }
    
                rev = rev * 10 + digit;
                x /= 10;
            }
    
            return (rev == num);
        }
    };

    int main() {
        Solution s;
        
        int n;
        cout << "Enter a number: ";
        cin >> n;
    
        if (s.isPalindrome(n))
            cout << n << " is a Palindrome\n";
        else
            cout << n << " is Not a Palindrome\n";
    
        return 0;
    }