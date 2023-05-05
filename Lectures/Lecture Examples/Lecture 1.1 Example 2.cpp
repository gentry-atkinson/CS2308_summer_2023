#include<iostream>

using namespace std;

int foo(int a){
    if (a < 2)
        return 0;
    else if (a < 10)
        return 5*a;
    else
        return a/10;
}

int main(int argc, char** argv){
    cout << "foo(a) is " << foo(2) << endl;
}