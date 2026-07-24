#include<iostream>
using namespace std;
int main {
int arr[] = {1, 2, 3, 4, 5};
int n = sizeof(arr) / sizeof(arr[0]);

// Reverse the array
for (int i = 0; i < n / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[n - 1 - i];
    arr[n - 1 - i] = temp;
}

// Print the reversed array
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
cout << endl;

return 0;
}