#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

//for odered
int sequentialSearchOrdered(int arr[], int n, int key, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++; // Increment the comparison count

        if (arr[i] == key) {
            return i; // Return the index if the key is found
        } else if (arr[i] > key) {
            break; // Break the loop if the current element is greater than the key
        }
    }
}

// Binary Search (Assuming the array is sorted in ascending order)
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index where the target is found
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Return -1 if the target is not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 50, 62};
    int n = sizeof(arr) / sizeof(arr[0]);

    int linearTarget = 23;
    int linearResult = linearSearch(arr, n, linearTarget);

    if (linearResult != -1) {
        printf("Linear Search: %d found at index %d\n", linearTarget, linearResult);
    } else {
        printf("Linear Search: %d not found in the array\n", linearTarget);
    }

    int binaryTarget = 38;
    int binaryResult = binarySearch(arr, 0, n - 1, binaryTarget);

    if (binaryResult != -1) {
        printf("Binary Search: %d found at index %d\n", binaryTarget, binaryResult);
    } else {
        printf("Binary Search: %d not found in the array\n", binaryTarget);
    }

    return 0;
}
