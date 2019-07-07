

#include <iostream>
using namespace std;

int arr[]={10, 0 , 3, 5, 6, -15, 100};
int length=sizeof(arr)/sizeof(arr[0]);
void display(){
    for(int i=0;i<length;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(int first, int last){
    int p=arr[last];
    int pi = first;
    for(int i=first;i<last;i++){
        if(arr[i]<=p){
            swap(arr[pi], arr[i]);
            pi++;
        }
    }
    swap(arr[last], arr[pi]);
    return pi;
}
void quickSort(int low, int high){
    if(low<high){
        int index = partition(low, high);
        quickSort(low, index-1);
        quickSort(index+1, high);
    }
}
int main() {
    display();
    quickSort(0, length-1);
    display();
    return 0;
}

