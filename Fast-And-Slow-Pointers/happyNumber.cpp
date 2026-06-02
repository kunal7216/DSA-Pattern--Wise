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

**********************************************************************Brute Solution********************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNext(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;       // Extract last digit
            sum += digit * digit;     // Add square of digit
            n /= 10;                  // Remove last digit
        }

        return sum;
    }

    bool isHappy(int n) {
        // Brute force: run for a fixed number of iterations
        for (int i = 0; i < 1000; i++) {
            if (n == 1) {
                return true;
            }

            n = getNext(n);
        }

        return false;
    }
};
***********************************************************************Better Solution*******************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNext(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;       // Extract last digit
            sum += digit * digit;     // Add square of digit
            n /= 10;                  // Remove last digit
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> visited;

        while (n != 1) {
            // If current number already exists, cycle is detected
            if (visited.count(n)) {
                return false;
            }

            // Mark current number as visited
            visited.insert(n);

            // Move to next transformed number
            n = getNext(n);
        }

        return true;
    }
};
***********************************************************************Optimal Solution*******************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNext(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;       // Extract last digit
            sum += digit * digit;     // Add square of digit
            n /= 10;                  // Remove last digit
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            // Slow moves one step
            slow = getNext(slow);

            // Fast moves two steps
            fast = getNext(getNext(fast));

        } while (slow != fast);

        // If both meet at 1, it is a happy number
        return slow == 1;
    }
};
