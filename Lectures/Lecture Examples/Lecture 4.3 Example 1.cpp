#include<iostream>

using namespace std;

class C{
    private:
        string value;

    public:
        C(string);
        string getValue();
        void setValue(string);
};

C::C(string v){
    value = v;
}

string C::getValue(){
    return value;
}

void C::setValue(string v){
    value = v;
}

int main(int argc, char** argv){
    C instanceOfC("CS");
    cout << instanceOfC.getValue();
    instanceOfC.setValue(" is ");
    cout << instanceOfC.getValue();
    instanceOfC.setValue("best!");
    cout << instanceOfC.getValue() << endl;
    return 0;
} //try to guess the output