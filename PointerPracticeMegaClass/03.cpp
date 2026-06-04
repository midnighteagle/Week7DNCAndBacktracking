#include<iostream>
using namespace std;
void swap (int *x , int *y){
    int t;
    t = *x;
    *x = *y;
    *y = t;
}
int main()
{
    int a = 10;
    int b = 20;
    swap (a,b);
    swap(&a, &b);
    cout<< "a: "<<a<<" b: "<<b<<endl; // teacher says it gives error. and address &a, &b;
}