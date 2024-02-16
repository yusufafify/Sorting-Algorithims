#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    // 'key' is a temporary variable to hold the current element being considered
    // 'j' is used for comparisons and shifting elements
    int key, j;

    // Loop through the array starting from the second element (index 1)
    for (int i = 1; i < n; i++)
    {
        // Store the current element in 'key'
        key = arr[i];

        // Initialize 'j' to the index just before the current element
        j = i - 1;

        // While 'j' is greater than or equal to 0 and the element at 'arr[j]' is greater than 'key'
        while (j >= 0 && arr[j] > key) // if sorting descending let "arr[j] < key"
        {
            // Shift the greater element to the right
            arr[j + 1] = arr[j];

            // Move to the previous position for comparison
            j--;
        }

        // Place 'key' in its correct sorted position
        arr[j + 1] = key;
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

    insertionSort(arr, n);
    cout << "Array after insertion sorting:" << endl;
    printArr(arr, n);

    return 0;
}