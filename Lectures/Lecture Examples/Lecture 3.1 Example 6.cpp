#include<iostream>

using namespace std;


int* makeAnInt(){
    int a = 3;
    return &a;
}


int main(int argc, char** argv){
    int* b = makeAnInt();
    cout << "b is " << *b << endl;
} //This program causes an error!