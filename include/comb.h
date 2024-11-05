#ifndef COMB_H
#define COMB_H

#include <iostream>
#include <cmath>

class CombSort {
    int* arr;
    int size;

    static void swap(int* a, int* b) {
        const int temp = *a;
        *a = *b;
        *b = temp;
    }

public:
    CombSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

    void sort() const {
        if (size <= 1) return;

        int gap = size;
        bool swapped = true;

        while (gap > 1 || swapped) {
            constexpr float shrinkFactor = 1.3;
            gap = static_cast<int>(std::floor(gap / shrinkFactor));
            if (gap < 1) {
                gap = 1;
            }

            swapped = false;

            for (int i = 0; i < size - gap; i++) {
                if (arr[i] > arr[i + gap]) {
                    swap(&arr[i], &arr[i + gap]);
                    swapped = true;
                }
            }
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