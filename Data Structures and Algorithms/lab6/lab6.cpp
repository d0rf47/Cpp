/**************************************************/
/*                                                */
/*  Lab 6 Starter file                            */
/*                                                */
/*  Name:Michael                                  */
/*  Student number:143152189                      */
/*                                                */
/**************************************************/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "timer.h"

using namespace std;
//arrays smaller than threshold will be insertionsorted
const int threshold = 16;

int selectMedian(int left, int mid, int right)
{
    int median = mid;
    if (left < mid && right > mid)
        return median;
    else if (left > mid && left < right)
        return left;
    else if (right > left && right < left)
        return right;
    return median;
}


/*performs the insertion sort algorithm on array from index
left to index right inclusive*/
void insertionSort(int arr[], int left, int right) {
    int curr;
    int i, j;
    for (i = left + 1; i <= right; i++) {
        curr = arr[i];
        for (j = i; j > 0 && arr[j - 1] > curr; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = curr;
    }
}


int partitionLast(int array[], int left, int right) {
    //choose right most value of partition for pivot
    int location = right - 1;
    int pivot = array[location];
    array[location] = array[right];
    array[right] = pivot;

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i = i + 1;
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    int tmp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = tmp;
    return i + 1;
}
int partitionMiddle(int array[], int left, int right) {
    //choose middle element for pivot
    int location = (left + right) / 2;
    int pivot = array[location];
    array[location] = array[right];
    array[right] = pivot;

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i = i + 1;
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    int tmp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = tmp;
    return i + 1;
}
int partitionMedianOf3(int array[], int left, int right) {
    //choose the median of the three values
    //at array[left], array[middle], array[right]
    //as pivot
    int mid = (left + right) / 2;
    int location = selectMedian(left, mid, right);
    int pivot = array[location];
    array[location] = array[right];
    array[right] = pivot;

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i = i + 1;
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    int tmp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = tmp;
    return i + 1;
}
int partitionRandom(int array[], int left, int right) {
    //choose random element between array[left] and
    //array right as median
    int location = left + (rand() % (right - left + 1));
    int pivot = array[location];
    array[location] = array[right];
    array[right] = pivot;

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i = i + 1;
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    int tmp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = tmp;
    return i + 1;
}

void quickSortMiddle(int arr[], int left, int right) {
    if (right - left <= threshold) {
        insertionSort(arr, left, right);
    }
    else {
        int i = partitionMiddle(arr, left, right);
        quickSortMiddle(arr, left, i - 1);
        quickSortMiddle(arr, i + 1, right);
    }
}
void quickSortMedianOf3(int arr[], int left, int right) {
    if (right - left <= threshold) {
        insertionSort(arr, left, right);
    }
    else {
        int i = partitionMedianOf3(arr, left, right);
        quickSortMedianOf3(arr, left, i - 1);
        quickSortMedianOf3(arr, i + 1, right);
    }
}
void quickSortLast(int arr[], int left, int right) {
    if (right - left <= threshold) {
        insertionSort(arr, left, right);
    }
    else {
        int i = partitionLast(arr, left, right);
        quickSortLast(arr, left, i - 1);
        quickSortLast(arr, i + 1, right);
    }
}
void quickSortRandom(int arr[], int left, int right) {
    if (right - left <= threshold) {
        insertionSort(arr, left, right);
    }
    else {
        int i = partitionRandom(arr, left, right);
        quickSortRandom(arr, left, i - 1);
        quickSortRandom(arr, i + 1, right);
    }
}
void quickSortLast(int arr[], int size) {
    quickSortLast(arr, 0, size - 1);
}
void quickSortMiddle(int arr[], int size) {
    quickSortMiddle(arr, 0, size - 1);
}
void quickSortMedianOf3(int arr[], int size) {
    quickSortMedianOf3(arr, 0, size - 1);
}
void quickSortRandom(int arr[], int size) {
    quickSortRandom(arr, 0, size - 1);
}
