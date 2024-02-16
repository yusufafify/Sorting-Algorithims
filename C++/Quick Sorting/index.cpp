#include <iostream>
using namespace std;

// function to swap the variables
void swapVaribales(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
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
    int arr[] = {-2, -68, 5, -11, 42, 0, 48, 5, 97, -46, -44, -2, 5, -80, -22, 66, 28, -80, -95, -19, -99, -14, -77, -90, 39, 0};
    int n = sizeof(arr) / sizeof(arr[0]); // get the size of the array
    // sizeof(arr) gets the size of the array in bytes= 6 * 4 =24 -> 6=number of elements 4= each element takes 4 bytes from the memory
    // sizeof(arr[0]) gets the size of bytes the element takes =4

    cout << "Array before sorting:" << endl;
    printArr(arr, n);

    quickSort(arr, 0, n - 1);
    cout << "Array after selection sorting:" << endl;
    printArr(arr, n);

    return 0;
}