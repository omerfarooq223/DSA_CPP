#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        std::swap(arr[minIndex], arr[i]);
    }
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    std::cout << "Sorted array (ints): ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    double dArr[] = {3.5, 1.2, 4.8, 2.1};
    int dn = sizeof(dArr) / sizeof(dArr[0]);

    selectionSort(dArr, dn);

    std::cout << "Sorted array (doubles): ";
    for (int i = 0; i < dn; i++) {
        std::cout << dArr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}