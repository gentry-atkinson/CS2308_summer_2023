#include<iostream>

using namespace std;


int main(int argc, char** argv){
    int a[] = {1, 2, 3, 4, 5};
    cout  << "Address of array first element: " << &a[0] << endl;
    cout << "Value stored in a: " << a << endl;
    cout << "First element in a: " << a[0] << endl;
    cout << "Dereferencing a: " << *a << endl;
    cout << "Second element in a: " << a[1] << endl;
    cout << "Dereferencing a+1: " << *(a+1) << endl;
    return 0;
} //try to predict the output