#include<iostream>

using namespace std;

class Circle{
    private:
        const float PI = 3.14159;
        float radius, circum, area;

    public:
        Circle(float r){
            radius = r;
            area = PI*(radius*radius);
            circum = PI*(2*radius);
        }

        float getArea(){return area;}
};

int main(int argc, char** argv){
    Circle c(5);
    cout << c.getArea() << endl;
} //try to guess the output