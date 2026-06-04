#include<iostream>
using namespace std;

int main()
{
    int i = 4;
    int *j;
    int *k;
    j= &i;
    
    j = j+1; // add of i + 4
    j = j+9; // address of i + (9*4)
    j = j+3; // address of i + (3 * 4)

}