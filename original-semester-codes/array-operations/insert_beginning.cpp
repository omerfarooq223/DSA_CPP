#include <iostream>
using namespace std;

int main() {
    int arr[6] = {10, 20, 30, 40, 50};
    int n = 5; // current number of elements
    int newElement = 5;

    // Shift elements to the right
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = newElement; // insert at beginning
    n++;

    cout << "Array after inserting at beginning: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
