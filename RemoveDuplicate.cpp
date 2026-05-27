#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 1, 2, 2, 3, 4, 4, 5}; // example input
    int n = a.size();

    int i = 0;
    for (int j = 1; j < n; j++) {
        if (a[i] != a[j]) {
            i++;
            a[i] = a[j];
        }
    }

    // Print unique elements
    for (int k = 0; k <= i; k++) {
        cout << a[k] << " ";
    }
    cout << endl;

    return 0;
}

