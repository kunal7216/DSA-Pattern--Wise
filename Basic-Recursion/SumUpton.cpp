#include<iostrem>
using namespace std;

class solution{
public:
    int sumUpto(int n){
        //base case
        if(n==0){
            return 0;
        }
        //recursive case
        return n + sumUpto(n-1);
    }
}

int main(){
    solution obj;
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int result = obj.sumUpto(n);
    cout<<"Sum from 1 to "<<n<<" is: "<<result<<endl;
    return 0;
}