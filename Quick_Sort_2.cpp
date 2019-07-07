

#include <iostream>
#include <conio.h>
using namespace std;

int partition (int arr[], int low, int high) {

    int pivot = arr[high];
    int i = low;

    for (int j = low; j <= high-1; j++) {
    
          if (arr[j] <= pivot) {
          swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return (i);
}

void quickSort(int arr[], int low, int high {

          if (low < high) {
        int pi = partition(arr, low, high);   //For partitioning the array....

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main ( )  {

    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter the values of array : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"Before sorting : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    quickSort(arr,0,size-1);

    cout<<"After sorting : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    getch();
    return 0;
}
