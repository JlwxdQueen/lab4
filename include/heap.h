#ifndef HEAP_H
#define HEAP_H

#include <iostream>

class HeapSort {
    int* arr;
    int size;

    void heapify(int n, int i) const {
        int largest = i;
        const int left = 2 * i + 1;
        const int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(&arr[i], &arr[largest]);
            heapify(n, largest);
        }
    }

    void buildHeap() const {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(size, i);
        }
    }

    void heapSort() const {
        buildHeap();

        for (int i = size - 1; i > 0; i--) {
            swap(&arr[0], &arr[i]);
            heapify(i, 0);
        }
    }

    static void swap(int* a, int* b) {
        const int temp = *a;
        *a = *b;
        *b = temp;
    }

public:
    HeapSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

    void sort() const {
        if (size <= 1) return;
        heapSort();
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
