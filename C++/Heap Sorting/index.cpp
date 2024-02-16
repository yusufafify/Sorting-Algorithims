#include <iostream>
using namespace std;


void heapify(int arr[],int n, int i){
    int leftChild=2*i+1;
    int rightChild=2*i+2;
    int max=i;
    if(leftChild<n && arr[leftChild]>arr[max]){
        max=leftChild;
    }
    if(rightChild<n && arr[rightChild]>arr[max]){
        max=rightChild;
    }
    if(max!=i){
        swap(arr[i],arr[max]);
        heapify(arr,n,max);
    }
}

void buildHeap(int arr[],int n){
    for(int i=(n-1)/2; i>=0; i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr,n);
    for (int i = n-1; i >=0; i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
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
    int arr[] = {-2, -68, 5, -11, 42, 0, 48, 5, 97, -46, -44, -2, 5, -80, -22, 66, 28, -80, -95, -19, -99, -14, -77, -90, 39, 0};
    int n = sizeof(arr) / sizeof(arr[0]); // get the size of the array
    // sizeof(arr) gets the size of the array in bytes= 6 * 4 =24 -> 6=number of elements 4= each element takes 4 bytes from the memory
    // sizeof(arr[0]) gets the size of bytes the element takes =4

    cout << "Array before sorting:" << endl;
    printArr(arr, n);

    heapSort(arr, n);
    cout << "Array after insertion sorting:" << endl;
    printArr(arr, n);

    return 0;
}