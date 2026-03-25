#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void BubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) 
          break;
    }
}

int main() {
    char charArr[] = {'g', 'x', 'z', 'a', 'd', 'c', 'y'};
    int charSize = sizeof(charArr) / sizeof(charArr[0]);

    BubbleSort(charArr, charSize);

    std::cout << "Sorted characters: ";
    for (int i = 0; i < charSize; i++) {
        std::cout << charArr[i] << " ";
    }
    std::cout << "\n";

    int intArr[] = {5, 2, 9, 1, 5, 6};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);

    BubbleSort(intArr, intSize);

    std::cout << "Sorted integers: ";
    for (int i = 0; i < intSize; i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}