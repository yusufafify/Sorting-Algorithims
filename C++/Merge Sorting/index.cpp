#include <iostream>
using namespace std;

// function to merge
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1], *R = new int[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    i = j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSorting(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSorting(arr, l, m);
        mergeSorting(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// function to print the array
void printArr(int arr[], int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    };
    cout << "]" << endl;
}

int main()
{
    int arr[] = {-60, 0, 20, 10, 30, 50};
    int n = sizeof(arr) / sizeof(arr[0]); // get the size of the array
    // sizeof(arr) gets the size of the array in bytes= 6 * 4 =24 -> 6=number of elements 4= each element takes 4 bytes from the memory
    // sizeof(arr[0]) gets the size of bytes the element takes =4

    cout << "Array before sorting:" << endl;
    printArr(arr, n);

    mergeSorting(arr, 0, n - 1);
    cout << "Array after merge sorting:" << endl;
    printArr(arr, n);

    return 0;
}