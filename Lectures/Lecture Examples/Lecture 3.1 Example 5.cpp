#include<iostream>

using namespace std;

//Double the value of a by reference parameter
void refFunc(int &X){
    X *= 2;
    return;
}

//Same thing but with pointers
void ptrFunc(int* X){
    *X *= 2;
    return;
}


int main(int argc, char** argv){
    int a =2;
    refFunc(a);
    cout << a << endl;
    return 0;
} //try to predict the output