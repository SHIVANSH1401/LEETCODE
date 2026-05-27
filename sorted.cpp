#include <iostream>
#include <vector>
using namespace std;

bool isSorted(int n, const vector<int>& a) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return false;  // Found unsorted pair
        }
    }
    return true;  // All pairs are in order
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};  // Example array

    if (isSorted(arr.size(), arr)) {
        cout << "Array is sorted" << endl;
    } else {
        cout << "Array is not sorted" << endl;
    }

    return 0;
}
