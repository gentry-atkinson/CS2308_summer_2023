#include<iostream>

using namespace std;

class Circle{
    private:
        const float PI = 3.14159;

    public:
        float radius, circum, area;
};

int main(int argc, char** argv){
    Circle c;
    cout << c.PI << endl;
} //try to predict the output