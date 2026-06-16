// sum of two integers
// leetcode 371

****************************************************************Brute Solution**************************************************************************************
    class Solution {
public:
    int getSum(int a, int b) {

        // If b is positive
        while (b > 0) {
            a++;
            b--;
        }

        // If b is negative
        while (b < 0) {
            a--;
            b++;
        }

        return a;
    }
};
****************************************************************Better Solution**************************************************************************************
    class Solution {
public:
    int getSum(int a, int b) {

        while (b != 0) {

            // Carry
            unsigned int carry = (unsigned int)(a & b);

            // Sum without carry
            a = a ^ b;

            // Shift carry
            b = carry << 1;
        }

        return a;
    }
};
****************************************************************Optimal Solution**************************************************************************************
    class Solution {
public:
    int getSum(int a, int b) {

        while (b != 0) {

            // carry bits
            unsigned carry = (a & b);

            // sum without carry
            a = a ^ b;

            // shifted carry
            b = carry << 1;
        }

        return a;
    }
};
