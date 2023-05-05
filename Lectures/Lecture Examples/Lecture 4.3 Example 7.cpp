#include<iostream>

using namespace std;

class C{
    private:
        int *a;
    public:
        C(){
            a = new int;
            *a = 5;
        }
        ~C(){delete a;}
        void printA(){
            cout << *a;
        }
};


int main(int argc, char** argv){
    C* c = new C;
    c->printA();
    delete c;
    return 0;
} //try to guess the output
