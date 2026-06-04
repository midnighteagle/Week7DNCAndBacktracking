#include<iostream>
using namespace std;
int main()
{
    int i = 3;
    int *j;
    j = &i;

    cout<<"the value of = "<<i<<endl; // 3
    cout<<"the value of = "<<&i<<endl; // address of i
    cout<<"the value of = "<<j<<endl; // address of i
    cout<<"the value of = "<<&j<<endl; // address of j
    cout<<"the value of = "<<*(&i)<<endl; // 3
    cout<<"the value of = "<<*j<<endl; // 3


}