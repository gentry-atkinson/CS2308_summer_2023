#include<iostream>
#include<cstdlib>

using namespace std;

//This function de-allocates its memory
void notLeakyFunc(){
    int* p = new int;
    *p  = rand();
    cout << *p << endl;
    delete p;
}

int main(int argc, char** argv){
    for(int i = 0; i < 1000; i++)
        notLeakyFunc();
} //try to predict the output