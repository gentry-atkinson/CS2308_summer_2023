#include<iostream>

using namespace std;

int main(int argc, char** argv){
    const int SIZE = 3;
    int a[SIZE] = {1, 2, 3};
    for(int i = 1; i <= SIZE; i++){
        cout << "a [" << i << "] is " << a[i];
        cout << endl;
    } 
    return 0;
} //try to predict the output