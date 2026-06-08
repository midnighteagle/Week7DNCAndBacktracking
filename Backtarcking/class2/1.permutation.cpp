#include<iostream>
using namespace std;
void printPermutation(string str, int i){
    // base case 
    if(i >= str.length()){
        // print
        cout<< str << endl;
        return;
    }
    // 1 case main solve krunga baki recursion sambhal lega
    // 1 case -> main i wale dabbe k upar , har ek element ko chance dunga
    for(int j = i; j < str.length(); j++){
        // chance dene ke liye swap kiya tha 
        swap(str[i], str[j]);
        // baki recursion sambhal lega 
        printPermutation( str, i+1);
    }
}
void printPermutation1(string &str, int i){
    // base case 
    if(i >= str.length()){
        // print
        cout<< str << endl;
        return;
    }
    // 1 case main solve krunga baki recursion sambhal lega
    // 1 case -> main i wale dabbe k upar , har ek element ko chance dunga
    for(int j = i; j < str.length(); j++){
        // chance dene ke liye swap kiya tha 
        swap(str[i], str[j]);
        // baki recursion sambhal lega 
        printPermutation1( str, i+1);
        // backtracking
        swap(str[i], str[j]);
    }
}
int main(){
    string str = "abc";
    int i = 0;
    printPermutation1(str, i);
    return 0;
}