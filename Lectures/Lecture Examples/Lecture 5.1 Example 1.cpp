#include<iostream>

using namespace std;

class C{
    private:
        
    public:
        static int howMany;
        C(){howMany++;};
        int getHowMany(){return howMany;};
};

int C::howMany = 0;

int main(int argc, char** argv){
    C a, b, c, d;
    cout << "Class variable: " << C::howMany << endl;
    cout << "a's member variable: " << a.getHowMany() << endl;
    cout << "b's member variable: " << b.getHowMany() << endl;
    cout << "c's member variable: " << c.getHowMany() << endl;
    cout << "d's member variable: " << d.getHowMany() << endl;
    return 0;
} //try to guess the output