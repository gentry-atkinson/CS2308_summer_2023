#include<iostream>
#include "Employee.h"

using namespace std;

class Employee{
    private:
        string name;
        string title;
        float hourlyRate;
    public:
        Employee();
        Employee(const Employee&);
};

Employee::Employee(){
    name = "";
    title = "";
    hourlyRate = 0;
}

Employee::Employee(const Employee& e){
    name = e.name;
    title = e.title;
    hourlyRate = e.hourlyRate;
}


int main(int argc, char** argv){
    Employee a;
    Employee b(a);
} //try to guess the output
