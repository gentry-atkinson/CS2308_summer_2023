#include<iostream>

using namespace std;

void foo(string param){
    cout << "param was passed" << param << endl;
    return;
}

int main(int argc, char** argv){
    cout << "calling foo with the argument \"bar\"" << endl;
    foo("bar");
    return 0;
} //try to predict the output