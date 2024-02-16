#include <iostream>
using namespace std;

// function to swap the variables
void swapVaribales(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSorting(int arr[], int n)
{
    int minIdx;
    for (int i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swapVaribales(arr[i], arr[minIdx]);
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
    //sizeof(arr[0]) gets the size of bytes the element takes =4

    cout << "Array before sorting:" << endl;
    printArr(arr, n);

    selectionSorting(arr, n);
    cout << "Array after selection sorting:" << endl;
    printArr(arr, n);

    return 0;
}