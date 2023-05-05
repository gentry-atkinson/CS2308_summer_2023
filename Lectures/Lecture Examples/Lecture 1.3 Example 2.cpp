#include<iostream>

using namespace std;

struct Rectangle{
    float length, width, area;
    Rectangle(){
        length = 1;
        width = 1;
        area = 1;
    }
    Rectangle(float l, float w){
        length = l;
        width = w;
        area = length*width;
    }
};

int main(int argc, char** argv){
    Rectangle a(1,2);
    cout << "Rectangle a has area " << a.area << endl;
} //try to predict the output