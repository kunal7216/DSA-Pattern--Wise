#include<iostream>
using namespaces std;

void reverseArray(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    // Swap the elements at start and end
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    
    // Recursive call for the next pair
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    reverseArray(arr, 0, n - 1);
    
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
