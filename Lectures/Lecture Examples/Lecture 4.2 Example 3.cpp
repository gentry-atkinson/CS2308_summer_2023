#include<iostream>

using namespace std;

class Circle{
    private:
        const float PI = 3.14159;
        float radius, circum, area;

    public:
        void setMembers(float radius){
            this->radius = radius;
            area = PI*(radius*radius);
            circum = PI*(2*radius);
        }
        float getArea(){return area;}
};

int main(int argc, char** argv){
    Circle c;
    c.setMembers(5);
    cout << c.getArea() << endl;
} //try to guess the output