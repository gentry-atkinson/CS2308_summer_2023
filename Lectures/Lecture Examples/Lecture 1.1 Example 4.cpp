#include<iostream>

using namespace std;

void foo(){
    int a = 3;
    cout << "a in foo is " << a << endl;
    return;
}

int main(int argc, char** argv){
    int a = 2;
    cout << "a in main is " << a << endl;
    foo();
    return 0;
} //try to predict the output