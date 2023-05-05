#include<iostream>

using namespace std;

class C{
    private:
        int *a;
    public:
        void setA(int* a){
            this->a=a;
        }
        void printA(){
            cout << *a << endl;
        }
};


int main(int argc, char** argv){
    C c;
    int b = 5;
    c.setA(&b);
    c.printA();
    return 0;
} //try to guess the output
