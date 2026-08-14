// Quick Sort - Hoare's Partition
// https://www.geeksforgeeks.org/dsa/hoare-s-partition-algorithm/
#include <iostream>
using namespace std;

// Hoare's Partition function
int partition(int a[], int lb, int ub) {
    int i, j, pivot;

    pivot = a[lb];                  // Choosing the first element as pivot
    i = lb - 1;
    j = ub + 1;

    while (true) {

        // Move i from left(to right) until an element >= pivot is found
        do {
            i++;
        } while (a[i] < pivot);

        // Move j from right(to left) until an element <= pivot is found
        do {
            j--;
        } while (a[j] > pivot);

        // If pointers cross, return partition index
        if (i >= j)
            return j;

        // Swap elements
        swap(a[i], a[j]);
    }
}

// Quick Sort recursive function
void quicksort(int a[], int lb, int ub) {
    int p;

    if (lb < ub) {
        p = partition(a, lb, ub);

        quicksort(a, lb, p);
        quicksort(a, p + 1, ub);
    }
}

// Main function
int main() {
    int a[20], n, i;

    cout << "Enter the no. of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "\nUnsorted Array:\n";
    cout << "[";
    for (i = 0; i < n; i++) {
        cout << " " << a[i];
    }
    cout << " ]\n";

    quicksort(a, 0, n - 1);

    cout << "\nSorted Array:\n";
    cout << "[";
    for (i = 0; i < n; i++) {
        cout << " " << a[i];
    }
    cout << " ]\n";

    return 0;
}