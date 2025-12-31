#include<iostream>
using namespace std;

// Function to reverse the digits of an integer 'n'.
int reverseInt(int n){
    // Initialize a variable 'rev' to store the reversed integer.
    int rev = 0;
    // While loop iterates until 'n' becomes 0 (no more digits left).
    while(n > 0){
        // Extract the last digit of 'n' using modulus operator.
        int digit = n % 10;

        if(rev >INT_MAX/10 || rev < INT_MIN/10){
            return 0; // Return 0 in case of overflow
        }
        // Append the extracted digit to 'rev' by multiplying 'rev' by 10 and adding 'digit'.
        rev = rev * 10 + digit;
        // Remove the last digit from 'n' by performing integer division by 10.
        n = n / 10;
    }
    // Return the reversed integer.
    return rev;
}
