#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    bool isPrime = true;

    if(n <= 1){            // 0 and 1 are not prime numbers
        isPrime = false;
    } else {
        for(int i = 2; i <= sqrt(n); i++){     // Check for factors from 2 to sqrt(n)
            if(n % i == 0){                    // If n is divisible by i, it's not prime
                isPrime = false;
                break;
            }
        }
    }

    if(isPrime){
        cout<<n<<" is a prime number."<<endl;
    } else {
        cout<<n<<" is not a prime number."<<endl;
    }

    return 0;
}