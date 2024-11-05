#ifndef BINARY_INSERTION_H
#define BINARY_INSERTION_H

#include <iostream>

class BinaryInsertionSort {
    int* arr;
    int size;

public:
    BinaryInsertionSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

    void sort() const {
        if (size <= 1) return;

        for (int i = 1; i < size; i++) {
            const int key = arr[i];
            int left = 0;
            int right = i;

            while (left < right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] <= key) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            for (int j = i; j > left; j--) {
                arr[j] = arr[j - 1];
            }
            arr[left] = key;
        }
    }

    void sortAndPrint() const {
        sort();
        std::cout << "Отсортированный массив: ";
        printArray();
    }

private:
    void printArray() const {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif
