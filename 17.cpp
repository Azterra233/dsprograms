// Selection Sort
#include <iostream>
using namespace std;

void selectionsort(int a[], int lb, int ub)
{
    int i, j, n, minindex;

    n = ub - lb + 1;

    for (i = 0; i < n - 1; i++)
    {
        minindex = i;

        for (j = i + 1; j < n; j++)
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

    cout << "Unsorted Array:\n";
    cout << "[";
    for (i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << " ]\n";

    selectionsort(a, 0, n - 1);

    cout << "Sorted Array:\n";
    cout << "[";
    for (i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << " ]\n";

    return 0;
}