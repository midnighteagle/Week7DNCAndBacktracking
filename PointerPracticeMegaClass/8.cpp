#include<iostream>
using namespace std;
int main(){

    int x[3][5] ={
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };

    // int *n = &x;
    // int (*n)[5] = x;
    int *n = &x[0][0];
    
    cout<< "ans1: "<<*(*x)<<endl;
    cout<< "ans2: "<<*(*x+1)<<endl;
    cout<< "ans3: "<<*(*x+2)<<endl;
    cout<< "ans4: "<<*(*x+3)<<endl;
    cout<< "ans5: "<<*(*x+4)<<endl;
    cout<< "ans6: "<<*(*(x+1))<<endl;
    cout<< "ans7: "<<*(*(x+2)+1)<<endl;
    cout<< "ans8: "<<*(*x + 2) + 5<<endl;
    cout<< "ans9: "<<*(*(x)+2)+1<<endl;
    cout<< "ans10: "<<*(*(x+1)+3)<<endl;
    cout<< "ans11: "<<*n<<endl;
    cout<< "ans12: "<<*(n+2)<<endl;
    cout<< "ans13: "<<(*(n+3)+1)<<endl; 
    cout<< "ans14: "<<*(n+5)+1<<endl;
    cout<< "ans15: "<< *n++; // it give the error
} 