#include<iostream>

using namespace std;

int main(int argc, char** argv){
    const int SIZE = 3;
    int a[SIZE][SIZE] = {
        {1, 2, 3},
        {2, 3, 4},
        {4, 5, 6}
    };
    for(int row = 0; row < SIZE; row++){
        for(int col = 0; col < SIZE; col++)
            cout << a[row][col] << ' ';
        cout << endl;        
    } 
    return 0;
} //try to predict the output