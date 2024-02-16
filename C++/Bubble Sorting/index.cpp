#include <iostream>
using namespace std;

// function to swap the variables
void swapVaribales(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSorting(int arr[], int n)
{
    bool isSorted; 
    int counter=0; //indication of how many passes happened
    for (int i = 0; i < n - 1; i++)
    {
        isSorted=true;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swapVaribales(arr[j], arr[j+1]);
                isSorted=false;
            }
            counter++; //if sorted then the counter = n-1
        }
        if(isSorted){
            break;
        }

    }
    cout<<"# of passes: "<<counter<<endl;
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
    int arr[] = {2,1,4,3,5,6};
    int n = sizeof(arr) / sizeof(arr[0]); // get the size of the array
    // sizeof(arr) gets the size of the array in bytes= 6 * 4 =24 -> 6=number of elements 4= each element takes 4 bytes from the memory
    //sizeof(arr[0]) gets the size of bytes the element takes =4

    cout << "Array before sorting:" << endl;
    printArr(arr, n);

    bubbleSorting(arr, n);
    cout << "Array after bubble sorting:" << endl;
    printArr(arr, n);

    return 0;
}