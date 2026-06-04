#include<iostream>
using namespace std;
void junk (int *i, int *j){
    *i = *i * *i;
    *j = *j * *j;
}
int main(){
    int i = 5;
    int j = 2;
    junk(&i, &j);
    // junk(i,j);
    cout<< "i: "<<i<<"  j: "<<j<<endl;
}