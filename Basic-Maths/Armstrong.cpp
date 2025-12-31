#include<iostream>
using namespace std;

int main(){
    int r, n, sum =0, temp;
    cout<<"Enter a number: ";
    cin>>n;

    temp = n;
    while(n > 0){
        r = n %10; //getting last digit
        sum = sum + (r* r* r);
        n = n/10; //removing last digit
    }
    if(temp == sum){
        cout<<temp<<" is an Armstrong number."<<endl;
    }
    else{
        cout<<temp<<" is not an Armstrong number."<<endl;
    }
    return 0;
}