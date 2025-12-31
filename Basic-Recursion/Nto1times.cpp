#include<iostream>
using namespace std;


class solution{
    public :
        void printno(int current){
            if(current <1){
                return;
            }

            // forward recursion
            cout<<current<<endl;
            printno(current-1);

            // backtracking
            printno(current-1);
            cout<<current<<endl;
        }
}

int main(){
    solution obj;
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    obj.printno(n);
    return 0;
}