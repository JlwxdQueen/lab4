#ifndef QUICK_H
#define QUICK_H

#include <iostream>

class QuickSort {
    int* arr;
    int size;

    static void swap(int* a, int* b) {
        const int temp = *a;
        *a = *b;
        *b = temp;
    }

    [[nodiscard]] int partition(const int low, const int high) const {
        const int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return i + 1;
    }

    void quickSort(const int low, const int high) const {
        if (low < high) {
            const int pivotIndex = partition(low, high);
            quickSort(low, pivotIndex - 1);
            quickSort(pivotIndex + 1, high);
        }
    }

public:
    QuickSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

    void sort() const {
        if (size <= 1) return;
        quickSort(0, size - 1);
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
