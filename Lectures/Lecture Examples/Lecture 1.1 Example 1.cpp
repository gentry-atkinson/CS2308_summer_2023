#include<iostream>

using namespace std;

int double_int (int x){
    return 2*x;
}

int main(int argc, char** argv){
    cout << "2 * 2 is " << double_int(2) << endl;
}