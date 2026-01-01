// sum of two integers
// leetcode 371

class Solution
{
public:
    int getSum(int a, int b)
    {

        /*
         Loop until there is no carry left.
         'b' is used to store the carry at each step.
        */
        while (b != 0)
        {

            /*
             Calculate the carry:
             - (a & b) identifies the bits where both a and b have 1
             - << 1 shifts the carry to the left by 1,
               because in addition carry affects the next higher bit
            */
            int tmp = (a & b) << 1;

            /*
             Update 'a' to be the sum without carry:
             - XOR (^) adds bits where only one of them is 1
             - This is equivalent to binary addition modulo 2
            */
            a = a ^ b;

            /*
             Update 'b' to be the carry for the next iteration
            */
            b = tmp;
        }

        /*
         When carry (b) becomes 0, 'a' contains the final sum
         This works for positive, negative, and mixed integers
        */
        return a;
    }
};
