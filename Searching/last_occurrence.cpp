#include <iostream>
using namespace std;

// Linear Search for last occurrence
int lastOccurrenceLinear(int arr[], int size, int key) {
    int lastIndex = -1;
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            lastIndex = i;
    return lastIndex;
}

// Binary Search for last occurrence (array must be sorted)
int lastOccurrenceBinary(int arr[], int size, int key) {
    int low = 0, high = size - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            result = mid;
            low = mid + 1; // search in right half
        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

int main() {
    int arr[] = {1, 2, 4, 4, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    int lastLinear = lastOccurrenceLinear(arr, size, key);
    int lastBinary = lastOccurrenceBinary(arr, size, key);

    if (lastLinear != -1)
        cout << "Last occurrence of " << key << " using Linear Search is at index: " << lastLinear << endl;
    else
        cout << "Element " << key << " not found using Linear Search." << endl;

    if (lastBinary != -1)
        cout << "Last occurrence of " << key << " using Binary Search is at index: " << lastBinary << endl;
    else
        cout << "Element " << key << " not found using Binary Search." << endl;

    return 0;
}
