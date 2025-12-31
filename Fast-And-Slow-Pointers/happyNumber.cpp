class Solution
{
private:
    int nextNumber(int n)
    {

        // This function calculates the next number in the sequence
        // by summing the squares of the digits of n
        int newNumber = 0;

        while (n != 0)
        {

            // Extract the last digit
            int num = n % 10;

            // Add the square of the digit
            newNumber += num * num;

            // Remove the last digit
            n = n / 10;
        }

        // Return the computed sum of squares
        return newNumber;
    }

public:
    bool isHappy(int n)
    {

        // Slow pointer starts at n
        int slowPointer = n;

        // Fast pointer starts at the next number of n
        int fastPointer = nextNumber(n);

        // Continue until fast pointer reaches 1 (happy number)
        // or slow and fast pointers meet (cycle detected)
        while (fastPointer != 1 && fastPointer != slowPointer)
        {

            // Move slow pointer one step
            slowPointer = nextNumber(slowPointer);

            // Move fast pointer two steps
            fastPointer = nextNumber(nextNumber(fastPointer));
        }

        // If fast pointer reaches 1, n is a happy number
        // Otherwise, a cycle exists and n is not happy
        return fastPointer == 1;
    }
};
