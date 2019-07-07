

#include<iostream>
using namespace std;

int array[50];
int array_size;
//int array[]={50,20,5,10,-5,2};
void init_array(){
    cout << "Enter total numbers: ";
    cin >> array_size;
    cout << "Enter "<< array_size << " Values:" << endl;
    for(int i=0;i<array_size;i++){
        cin >> array[i];
    }
}
void display_array(int A[ ],int array_size){
    for(int i=0;i<array_size ; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}
void selection_sort (int A[ ], int n) {
        // temporary variable to store the position of minimum element
        int minimum;
        // reduces the effective size of the array by one in  each iteration.
        for(int i = 0; i < n-1 ; i++)  {
           // assuming the first element to be the minimum of the unsorted array .
             minimum = i ;
          // gives the effective size of the unsorted  array .
            for(int j = i+1; j < n ; j++ ) {
                if(A[ j ] < A[ minimum ])  {                //finds the minimum element
                    minimum = j ;
                }
             }
        // putting minimum element on its proper position.
        int temp = A[ i ];
        A[ i ] = A[minimum];
        A[minimum] = temp;

        cout << "Iteration " << (i+1) << ": ";
        display_array(array,array_size);
        }
   }
int main(){
    init_array();
    selection_sort(array,array_size);
    display_array(array,array_size);
return 0;
}

