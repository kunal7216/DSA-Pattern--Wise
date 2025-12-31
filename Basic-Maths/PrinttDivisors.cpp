//********************************************Brute Force************************* */

//#include <iostream>
//#include <vector>
//#include<algorithm>
//using namespace std;
////class Solution {
//public:
//    vector<int> printDivisors(int n) {
//        vector<int> divisors; 
//        for (int i = 1; i <= n; i++) {
//            if (n % i == 0) {              // Check if i is a divisor of n
//                divisors.push_back(i);     // Add the divisor to the list
//            }
//        }
//        return divisors;
//    }
//};

//int main() {
//    int n;
//    cout << "Enter a number: ";
//    cin >> n;
//    Solution solution;                  // Create an instance of the Solution class
//    vector<int> divisors = solution.printDivisors(n); 
//    cout << "Divisors of " << n << " are: ";
//    for (int divisor : divisors) {
//        cout << divisor << " ";
//    } 
//    cout << endl;
//    return 0;
//}





//**************************************************Optimal solution****************** */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> printDivisors(int n) {
        vector<int> divisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i); // Add the divisor
                if (i != n / i) {     // Avoid adding the square root twice
                    divisors.push_back(n / i);     // Add the corresponding divisor
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        return divisors;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution solution;
    vector<int> divisors = solution.printDivisors(n);

    cout << "Divisors of " << n << " are: ";
    for (int divisor : divisors) {
        cout << divisor << " ";
    }
    cout << endl;

    return 0;
}