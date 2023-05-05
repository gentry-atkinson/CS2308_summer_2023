#include<iostream>

using namespace std;

void foo(int);

int main(int argc, char** argv){
    cout << "Calling foo with argument 2" << endl;
    foo(2);
    return 0;
} //try to predict the output

void foo(int a){
    cout << "foo passed " << a << endl;
    return;
}