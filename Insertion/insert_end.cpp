#include <iostream>
using namespace std;

int main() {
    int arr[6] = {10, 20, 30, 40, 50};
    int n = 5; // current number of elements
    int newElement = 60;

    arr[n] = newElement; // insert at end
    n++;

    cout << "Array after inserting at end: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
