// merge sort better perform on array or linkedlist
// Quick sort better perform on array or linkedlist
#include<iostream>
using namespace std;
// todos:
// create left and right array
// creating the heap memory of array.
// fill or copy the left and right array
// copy the original array -> value
// original array ka starting index 
// copying into left array.
// copy into right Array
// merge logic
void merge(int arr[], int s, int e, int mid){
    // create left and right array
    int leftLength = mid - s + 1;
    int rightLength = e - mid;
    // creating the heap memory of array.
    int *leftArr = new int [leftLength];
    int *rightArr = new int [rightLength];
    // fill or copy the left and right array
    // copy the original array -> value
    // original array ka starting index 
    int index = s;
    // copying into left array.
    for(int i = 0; i < leftLength; i++){
        leftArr[i] = arr[index];
        index++;
    }
    // copy into right Array
    index = mid + 1;
    for(int i = 0; i < rightLength; i++){
        rightArr[i] = arr[index];
        index++;
    }

    
    // merge logic
    int i = 0;
    int j = 0;
    int mainArrayIndex = s;

    while(i < leftLength && j < rightLength){
        if(leftArr[i] < rightArr[j]){
            arr[mainArrayIndex] = leftArr[i];
            i++;
            mainArrayIndex++;
        }
        else{
            arr[mainArrayIndex] = rightArr[j];
            j++;
            mainArrayIndex++;
        }
    }
    // now I have to handle the 2 cases discussed above in the merge 2 sorted array wala question se.
    while(i < leftLength){
        arr[mainArrayIndex] = rightArr[j];
        j++;
        mainArrayIndex++;
    }
    while(j < rightLength){
        arr[mainArrayIndex] = rightArr[j];
        j++;
        mainArrayIndex++;
    }
    // delete the heap memory
    delete[] leftArr;
    delete[] rightArr;

}
// todos:
// void return type function kro jisme parameter arr and uska size krenge 
// use two pointer start and end
// base case
// find mid kro jese binary search me krte the.
// left part recursion se solve krwao
// right part recursion se solve krwaao
// dono parts ko merge kr do.
void mergeSort(int arr[],int start, int end){
    
    // base case
    if(start >= end){
        return ;
    }
    // find the mid
    int mid = (start+end)/2;
    // left part recursion se solve krwao
    mergeSort(arr,start,mid);
    // right part recursion se solve krwaao
    mergeSort(arr, mid+1, end);
    // dono parts ko merge kr do.
    merge(arr,start,end,mid);
}
int main(){
    int arr[] ={12,10,11,5,9,25,2,7};
    int size = 8;
    int start = 0;
    int end = size-1;
    cout<<"before MergeSort"<<endl;
    for(int num : arr){
        cout<<num<<" ";
    }
    mergeSort(arr,  start, end);
    cout<<"after MergeSort"<<endl;
    for(int num : arr){
        cout<<num<<" ";
    }
    return 0;
}