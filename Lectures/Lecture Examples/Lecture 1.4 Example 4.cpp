#include<iostream>

using namespace std;

struct Dog{
    string breed; string name; int age;
};

bool bigDog(Dog &d){
    if(d.breed == "mastif"||d.breed=="dane"){
        return true;
    }
    return false;
}

int main(int argc, char** argv){
    Dog d = {"mastif", "Jimmy", 6};
    if(bigDog(d))
        cout << d.name << " is a big dog." << endl;
    else
        cout << d.name << " is a small dog." << endl; 
} //try to predict the output