#include<iostream>

using namespace std;

void foo(const int a[], int &b, int &c, int SIZE){
    b =  c = a[0];
    for(int i = 1; i < SIZE; i++){
        if(a[i] < b) b = a[i];
        if(a[i] > c) c = a[i];
    }
}

int main(int argc, char** argv){
    int a[] = {2, 6, 4, 8, 3, 4};
    int min, max;
    foo(a, min, max, 6);
    cout << "The minimum of a is " << min << endl;
    cout << "The maximum of a is " << max << endl;
} //try to predict the output