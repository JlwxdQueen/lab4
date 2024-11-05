#ifndef MERGE_H
#define MERGE_H

#include <iostream>

class MergeSort {
    int* arr;
    int size;

    static void merge(int* array, int left, int mid, int right) {
        const int n1 = mid - left + 1;
        const int n2 = right - mid;

        const auto leftArray = new int[n1];
        const auto rightArray = new int[n2];

        for (int i = 0; i < n1; i++) {
            leftArray[i] = array[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArray[j] = array[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                array[k] = leftArray[i];
                i++;
            } else {
                array[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            array[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < n2) {
            array[k] = rightArray[j];
            j++;
            k++;
        }

        delete[] leftArray;
        delete[] rightArray;
    }

    void mergeSort(int* array, int left, int right) const {
        if (left < right) {
            const int mid = left + (right - left) / 2;

            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);

            merge(array, left, mid, right);
        }
    }

public:
    MergeSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

    void sort() const {
        if (size <= 1) return;
        mergeSort(arr, 0, size - 1);
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
