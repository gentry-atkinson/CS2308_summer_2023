#include<iostream>

using namespace std;


int main(int argc, char** argv){
    int a = 1;
    int* b = &a;
    *b = 2*a;
    *b = 2*(*b);
    cout << "a is now " << *b << endl;
    return 0;
} //try to predict the output