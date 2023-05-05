#include<iostream>

using namespace std;


int main(int argc, char** argv){
    int * p = new int[20];
    *p = 8;
    p[1] = 2;
    cout << *p << endl;
    cout << p[1] << endl;
    cout << sizeof(*p) << endl;
} //try to predict the output
