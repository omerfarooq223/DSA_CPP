#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int countOccurrences(int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            count++;
    }
    return count;
}

int main() {
    int arr[] = {2, 4, 4, 1, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int index = linearSearch(arr, size, target);
    int occurrences = countOccurrences(arr, size, target);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
        cout << "Element found " << occurrences << " time(s) in the array." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
