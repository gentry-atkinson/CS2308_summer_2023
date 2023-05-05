#include<iostream>

using namespace std;

void foo(int a){
    a = 2*a;
    cout << "Value of a in foo"
        << a << endl;
}

int main(int argc, char** argv){
    int b = 2;
    cout << "Value b before foo: " 
        << b << endl;
    foo(b);
    cout << "Value b after foo: " 
        << b << endl; 
} //try to predict the output