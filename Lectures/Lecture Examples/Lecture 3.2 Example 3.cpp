#include<iostream>
#include<cstdlib>

using namespace std;

int* makeArr(){
    int*p = new int[10];
    for(int i = 0; i < 10; i++) p[i] = i;
    return p;
}

int main(int argc, char** argv){
    int * arr = makeArr();
    cout << arr[0] + arr[1] << endl;
    delete [] arr;
} //try to predict the output