/*

Write a program for analysis of quick sort by using deterministic and randomized variant.

*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function for deterministic QuickSort (using the last element as pivot)
int deterministicPartition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Deterministic QuickSort
void deterministicQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = deterministicPartition(arr, low, high);
        deterministicQuickSort(arr, low, pi - 1);
        deterministicQuickSort(arr, pi + 1, high);
    }
}

// Partition function for randomized QuickSort
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]); // Swap random pivot with last element
    return deterministicPartition(arr, low, high);
}

// Randomized QuickSort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Utility function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to copy an array
void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}

int main() {
    srand(time(0));  // Seed for random number generation

    const int size = 10000;  // You can change the size for larger arrays
    int arr[size], arrCopy[size];

    // Initialize the array with random numbers
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100000;

    // Copy the array to preserve the original for the second sort
    copyArray(arr, arrCopy, size);

    // Measure time for Deterministic QuickSort
    auto start = high_resolution_clock::now();
    deterministicQuickSort(arr, 0, size - 1);
    auto end = high_resolution_clock::now();
    auto deterministicDuration = duration_cast<milliseconds>(end - start).count();
    cout << "Deterministic QuickSort time: " << deterministicDuration << " ms" << endl;

    // Measure time for Randomized QuickSort
    start = high_resolution_clock::now();
    randomizedQuickSort(arrCopy, 0, size - 1);
    end = high_resolution_clock::now();
    auto randomizedDuration = duration_cast<milliseconds>(end - start).count();
    cout << "Randomized QuickSort time: " << randomizedDuration << " ms" << endl;

    return 0;
}
