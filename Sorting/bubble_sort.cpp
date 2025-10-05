#include <iostream>
using namespace std;

void BubbleSort(char arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) 
          break;
    }
}

int main() {
    char arr[] = {'g', 'x', 'z', 'a', 'd', 'c', 'y'};
    int size = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr, size);

    cout << "Sorted characters: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}