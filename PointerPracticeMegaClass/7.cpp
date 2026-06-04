#include<iostream>
using namespace std;
int main(){
    int num[] = {24,34,12,44,56,17};
    int i ;
    int *j;
    j = &num[0];
    for(i = 0; i <= 5; i++){
        cout<<j<<endl;; // address of nums [0,1,2,3,4,5]
        cout<<*j<<endl;; // derefrence of [24,34,12,44,56,17]
        j++;
    }
}