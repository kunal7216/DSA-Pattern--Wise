// Bitwise AND of Numbers Range
// leetcode.com/problems/bitwise-and-of-numbers-range/

******************************************************Brute Solution************************************************************************************************
    class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        int result = left;

        for (int i = left + 1; i <= right; i++) {
            result &= i;
        }

        return result;
    }
};
******************************************************Better Solution************************************************************************************************
    class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        int shiftCount = 0;

        while (left != right) {
            left >>= 1;
            right >>= 1;
            shiftCount++;
        }

        return left << shiftCount;
    }
};
******************************************************Optimal Solution*********************************************************************************************

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        while (right > left) {
            right = right & (right - 1);
        }

        return left & right;
    }
};
