#ifndef COUNTING_H
#define COUNTING_H

#include <iostream>

class CountingSort {
    int* arr;
    int size;

public:
    CountingSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

    void sort() const {
        if (size <= 1) return;

        int maxVal = arr[0];
        int minVal = arr[0];

        for (int i = 1; i < size; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
        }

        const int range = maxVal - minVal + 1;

        const auto count = new int[range]();
        const auto output = new int[size];

        for (int i = 0; i < size; i++) {
            count[arr[i] - minVal]++;
        }

        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; i >= 0; i--) {
            output[count[arr[i] - minVal] - 1] = arr[i];
            count[arr[i] - minVal]--;
        }

        for (int i = 0; i < size; i++) {
            arr[i] = output[i];
        }

        delete[] count;
        delete[] output;
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
