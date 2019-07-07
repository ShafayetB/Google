

#include <iostream>
#include <conio.h>
using namespace std;

//Mergesort Ascending_order....
void MergeAsc(char *a,int low,int high,int mid)
{
    int i,j,k,temp[high-low+1];
    i=low;
    j=mid+1;
    k=0;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            temp[k]=a[i];
            i++;
            k++;
        }
        else{
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=high){
        temp[k]=a[j];
        j++;
        k++;
    }

    for(int i=low;i<=high;i++){
        a[i]=temp[i-low];
    }
}

void merge_sortAsc(char *a,int low,int high)
{
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sortAsc(a,low,mid);
        merge_sortAsc(a,mid+1,high);

        MergeAsc(a,low,high,mid);
    }
}

//Mergesort Descending_order....
void MergeDsc(char *a,int low,int high,int mid)
{
    int i,j,k,temp[high-low+1];
    i=low;
    j=mid+1;
    k=0;
    while(i<=mid && j<=high){
        if(a[i]>a[j]){
            temp[k]=a[i];
            i++;
            k++;
        }
        else{
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=high){
        temp[k]=a[j];
        j++;
        k++;
    }

    for(int i=low;i<=high;i++){
        a[i]=temp[i-low];
    }
}

void merge_sortDsc(char *a,int low,int high)
{
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sortDsc(a,low,mid);
        merge_sortDsc(a,mid+1,high);


        MergeDsc(a,low,high,mid);
    }
}

//quicksort Ascending order...
int q_partitionAsc(char *a,int low,int high)
{
    int i,j,pivot;
    pivot=a[high];
    i=(low-1);

    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(a[j],a[i]);
        }
    }
    i++;
    swap(a[i],a[high]);
    return i;
}

void quick_sortAsc(char *a,int low,int high)
{
    int pivot;
    if(low<high){
        pivot=q_partitionAsc(a,low,high);

        quick_sortAsc(a,low,pivot-1);
        quick_sortAsc(a,pivot+1,high);
    }
}

//quicksort Descending order...
int q_partitionDsc(char *a,int low,int high)
{
    int i,j,pivot;
    pivot=a[high];
    i=(low-1);

    for(int j=low;j<high;j++){
        if(a[j]>pivot){
            i++;
            swap(a[j],a[i]);
        }
    }
    i++;
    swap(a[i],a[high]);
    return i;
}

void quick_sortDsc(char *a,int low,int high)
{
    int pivot;
    if(low<high){
        pivot=q_partitionDsc(a,low,high);

        quick_sortDsc(a,low,pivot-1);
        quick_sortDsc(a,pivot+1,high);
    }
}

int main()
{
    int input_size;
    cout<<"Enter the number of character:";
    cin>>input_size;
    char whole_input[input_size];
    cout<<"Your input data: ";
    for(int i=0;i<input_size;i++){
                cin>>whole_input[i];
    }
    //Take size of 1st part....
    int size_1st_part;
    cout<<"Enter the size of 1st part:";
    cin>>size_1st_part;

    //Take size of 2nd part...
    int size_2nd_part;
    cout<<"Enter the size of 2nd part:";
    cin>>size_2nd_part;


    cout<<"Select sort order for the first part(Merge Sort):"<<endl
    <<"1.Ascending"<<endl<<"2.Descending"<<endl;

    int choice_1st;
    cin>>choice_1st;

    cout<<"Select sort order for the second part(Quick Sort):"<<endl
    <<"1.Ascending"<<endl<<"2.Descending"<<endl;

    int choice_2nd;
    cin>>choice_2nd;

    char arr1[50];
    cout<<"Input for Merge Sort: ";
        for(int i=0;i<size_1st_part;i++){
            cin>>arr1[i];
    }

    char arr2[50];
    cout<<"Input for Quick Sort: ";
        for(int i=0;i<size_2nd_part;i++){
                cin>>arr2[i];
    }
    if(choice_1st==1){
        merge_sortAsc(arr1,0,size_1st_part-1);
    }
    if(choice_1st==2){
        merge_sortDsc(arr1,0,size_1st_part-1);
    }
    if(choice_2nd==1){
        quick_sortAsc(arr2,0,size_2nd_part-1);
    }
    if(choice_2nd==2){
        quick_sortDsc(arr2,0,size_2nd_part-1);
    }
    //Final output....
    cout<<"Sorted output data:";
    for(int i=0;i<size_1st_part;i++){
        cout<<arr1[i];
    }

    for(int i=0;i<size_2nd_part;i++){
        cout<<arr2[i];
    }

    getch();
    return 0;
}


