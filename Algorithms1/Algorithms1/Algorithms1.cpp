#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>

int partitionQ(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionQ(arr, low, high); // Get pivot index

        quickSort(arr, low, pi - 1);  // Sort left subarray
        quickSort(arr, pi + 1, high); // Sort right subarray
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];


    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        mergeSort(arr, left, mid);   // Sort first half
        mergeSort(arr, mid + 1, right); // Sort second half

        merge(arr, left, mid, right); // Merge the sorted halves
    }
}

// Main function
int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = size - 1;

    std::cout << "Original array: ";
    printArray(arr, size);

    mergeSort(arr, low, high);

    std::cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}