#include<iostream>

using namespace std;

class Circle{
    private:
        const float PI = 3.14159;

    public:
        float radius, circum, area;
        void setMembers(float radius){
            this->radius = radius;
            area = PI*(radius*radius);
            circum = PI*(2*radius);
        }
};

int main(int argc, char** argv){
    Circle c;
    c.setMembers(5);
    cout << c.area << endl;
} //causes an error