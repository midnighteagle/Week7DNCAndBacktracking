#include<iostream>
using namespace std;
void AddTwoArray(int arr[],int arrSize, int brr[],int brrSize, vector<int> &ans){
    int startArr = 0;
    int startBrr = 0;
    while(startArr < arrSize && startBrr < brrSize){

        if(arr[startArr] < brr[startBrr]){
            ans.push_back(arr[startArr]);
            startArr++;
        }
        else{
            ans.push_back(brr[startBrr]);
            startBrr++;
        }
    } 
    // agar main Yaha tak aa gaya 
    // toh 2 case ho sakte hai
    // 1 case -> arr me still elements bache hai 
    while(startArr < arrSize){
        ans.push_back(arr[startArr]);
        startArr++;
    }
    // 2 case -> brr me still elements bache hai 
    while(startBrr < brrSize){
        ans.push_back(brr[startBrr]);
        startBrr++;
    }
}
int main(){
    int arr[] = {10,30,50,70};
    int arrSize= 4;
    int brr[] = {20,40,60,80,90,100};
    int brrSize = 6;
    vector<int>ans;
    AddTwoArray(arr,arrSize,brr,brrSize,ans);
    for(int num : ans){
        cout<< num <<" ";
    }
    

    return 0;
}