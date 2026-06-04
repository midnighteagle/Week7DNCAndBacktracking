#include<iostream>
using namespace std;
int main()
{
    int i = 3;
    int *j;
    int **k;
    j = &i;
    k = &j;
    cout<<"the value of: "<<&i<<endl;// address of i
    cout<<"the value of: "<<j<<endl;// Address of i
    cout<<"the value of: "<<*k<<endl;// address of i
    cout<<"the value of: "<<&j<<endl;// address of j
    cout<<"the value of: "<<k<<endl; // address of j
    cout<<"the value of: "<<&k<<endl; // address of k
    cout<<"the value of: "<<j<<endl; // address of i
    cout<<"the value of: "<<k<<endl; //address of j 
    cout<<"the value of: "<<i<<endl; // 3
    cout<<"the value of: "<<*(&i)<<endl;//3
    cout<<"the value of: "<<*j<<endl; //3
    cout<<"the value of: "<<**k<<endl;//3
}