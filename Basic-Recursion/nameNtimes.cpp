#include<iostream>
using namespace std;

class Solution {
    public :
       void printname(string name, int count, int N){
            if(count ==N){
                return;
            }

            cout <<name<<" ";
            printname(name, count+1, N);
       }
};

int main(){
    string name;
    int N;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter the number of times to print your name: ";
    cin>>N;

    Solution sol;
    sol.printname(name, 0, N);

    return 0;
}