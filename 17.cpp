// Selection Sort
#include <iostream>
using namespace std;

void selectionsort(int a[], int lb, int ub)
{
    int i, j, n, minindex;

    n = ub - lb + 1;                        //range: calculates the total count of elements within the given boundary [lb, ub]

    for (i = 0; i < n - 1; i++)             //Outer loop running from the first element up to the second-to-last element (n - 2).
    {
        minindex = i;                       //minindex stores min. index; temporarily assumes the first element of the unsorted segment is the minimum.

        for (j = i + 1; j < n; j++)         //Inner loop scanning the remaining unsorted elements starting at i + 1.
        {
            if (a[lb + j] < a[lb + minindex])
            {
                minindex = j;
            }
        }

        swap(a[lb + minindex], a[lb + i]);
    }
}

int main()
{
    int a[20], n, i;

    cout << "Enter the no. of array elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "\nUnsorted Array:\n";
    cout << "[";
    for (i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << " ]\n";

    selectionsort(a, 0, n - 1);                       //Calls the sorting function on array a with lower bound 0 and upper bound n - 1.

    cout << "\nSorted Array:\n";
    cout << "[";
    for (i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << " ]\n";

    return 0;
}