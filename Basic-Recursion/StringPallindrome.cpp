#include <iostream>
#include <string>
using namespace std;

// Function to check if a string is a palindrome using recursion
bool palindrome(int i, string& s) {
    if (i >= s.length() / 2) return true;
    if (s[i] != s[s.length() - i - 1]) return false;
    return palindrome(i + 1, s);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (palindrome(0, s)) {
        cout << "It is a palindrome" << endl;
    } else {
        cout << "It is not a palindrome" << endl;
    }

    return 0;
}
