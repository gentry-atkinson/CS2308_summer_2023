#include<iostream>

using namespace std;

class C{
    private:
        int a[5] = {};
        int SIZE = 5;
    public:
        void printNums(){
            for(int i=0; i<SIZE;i++)
                cout << a[i] << ' ';
            cout << endl;
        }
};


int main(int argc, char** argv){
    C c[3];
    c[0].printNums();
    c[1].printNums();
    c[2].printNums();
    return 0;
} //try to guess the output
