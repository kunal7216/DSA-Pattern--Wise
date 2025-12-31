#include<iostresm>
using namespace std;

class solution{
public: 
    int factorialUpto(int n){
        //base case
        if(n==0){
            return 1;
        }
        //recursive case
        return n * factorialUpto(n-1);
    }
};

int main(){
    solution obj;
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int result = obj.factorialUpto(n);
    cout<<"Factorial of "<<n<<" is: "<<result<<endl;
    return 0;
}