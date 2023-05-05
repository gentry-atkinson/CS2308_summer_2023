#include<iostream>

using namespace std;

class C{
    private: int a;
    public:
        void setA(int a)
            {this->a = a;};
        int getA(){return a;};
};

class D{
    public: C c;

};

int main(int argc, char** argv){
    D d;
    d.c.setA(5);
    cout << d.c.getA() << endl;
    return 0;
} //try to guess the output
