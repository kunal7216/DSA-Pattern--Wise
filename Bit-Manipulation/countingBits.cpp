// counting bits
//leetcode 338

class Solution
{
public:
    vector<int> countBits(int n)
    {

        // dp[i] will store the number of set bits (1s) in the binary representation of i
        vector<int> dp(n + 1, 0);

        /*
         'sub' represents the largest power of 2 that is
         less than or equal to the current number i.
         Initially, the largest power of 2 <= 1 is 1.
        */
        int sub = 1;

        // Compute bit counts for all numbers from 1 to n
        for (int i = 1; i <= n; i++)
        {

            /*
             If i becomes exactly twice of 'sub',
             then i itself is a new power of 2.
             Update 'sub' to this new power of 2.
            */
            if (sub * 2 == i)
            {
                sub = i;
            }

            /*
             Any number i can be written as:
             i = (largest power of 2 <= i) + remainder

             dp[i - sub] gives the count of 1s in the remainder.
             Adding 1 accounts for the most significant bit (sub).
            */
            dp[i] = dp[i - sub] + 1;
        }

        // Return the array containing bit counts for all numbers from 0 to n
        return dp;
    }
};
