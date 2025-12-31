#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &arr, int target){
    int left =0;
    int right = arr.size()-1;

    while(left <= right){
        int mid = left + (right - left)/2;

        if(arr[mid] == target){
            return mid;
        }
        else if( arr[mid] < target){
            left = mid +1;
        }
        else{
            right = mid -1;
        }
    }
    return -1;
}

int main(){

    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72};
    int target = 56;

    int index = binarySearch(arr , target);

    if(index != -1){
        cout<<" element found at index : "<< index <<endl;
    }else{
        cout <<"element not found";
    }
    return 0;
}