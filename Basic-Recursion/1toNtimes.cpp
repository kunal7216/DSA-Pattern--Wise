#include<iostream>
using namespace std;

class solution {
    public :
        void printno(int currrent, int n){
            if(current >n){
                return;
            }

            // forward recursion
            cout<<current<<endl;           
            printno(current+1,n);

            // backtracking
            printno(current+1,n);
            cout<<current<<endl;
        }
}

int main(){
    solution obj;
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    obj.printno(1,n);
    return 0;
}