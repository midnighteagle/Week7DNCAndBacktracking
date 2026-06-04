#include<iostream>
using namespace std;
void quickSort(int a[], int start, int end){
    // Base Case 
    if(start >= end) return;

    // processing
    int pivot = end;
    int i = start - 1;
    int j = start;

    while(j < pivot){
        if(a[j] < a[pivot]){
            ++i;
            swap(a[i], a[j]);

        }
        j++;
    }
    ++i;
    swap(a[i], a[pivot]);

    // Recursive call
    quickSort(a, start, i - 1);
    quickSort(a, i + 1, end);
}
int main(){
    int a[] = {2,1,5,4,3,54,23,11}; 
    int n = sizeof(a) / sizeof(a[0]);

    int start = 0;
    int end = n - 1;
    cout<< "before sorting: "<<endl;
    for(int i = 0; i < n; i++){
        cout<< a[i] << " ";
    }
    cout<< endl;
    quickSort(a,start, end);

    cout<< "after sorting: "<<endl;
    for(int i = 0; i < n; i++){
        cout<< a[i] <<" ";
    }
    cout<< endl;
    return 0;
}