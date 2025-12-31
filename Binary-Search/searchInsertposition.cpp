#include<iostream>
using namespace std;

int insert(vector<int> &arr, int target){
    int n = arr.size();

    if(target < arr[0])return 0;
    if( target > arr[n-1]) return n;

    int low =0, high = n-1, ans;

    while(low <= high){
        int mid = (low + high)/2;

        if(arr[mid] == target)return mid;

        else if(arr[mid] < target) low = mid +1;

        else 
           ans = mid; // mid could be potential insert position
           high = mid -1;

    }
    return ans;
}