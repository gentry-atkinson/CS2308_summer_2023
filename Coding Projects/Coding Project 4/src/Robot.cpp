#include "../include/Robot.h"
#include <ctype.h>

using namespace std;

Robot::Robot(string name){
   this->name = name;
}
string Robot::getName(){return name;}
int Robot::getDistance(){return distance;}

void Robot::setName(string name){this->name = name;}
void Robot::moveRobot(char d){
    if(d=='s' || d=='S'){
        if(currentSpeed != 0){
            currentSpeed = 0;
            cout << name << " is now stopped" << endl;
            return;
        }
        else{
            currentSpeed = 1;
            lastCommand = 'z';
            cout << name << " is now moving" << endl;
            return;
        }
    }
    if (currentSpeed == 0){
        cout << "A robot cannot move while stopped!" << endl;
        return;
    }
    if(toupper(lastCommand) == toupper(d)){
        if(currentSpeed < 4) currentSpeed += 1;
    }
    else{
        currentSpeed = 1;
    }
    switch(d){
        case 'u':
        case 'U':
            y+=currentSpeed;
            distance += currentSpeed;
            break;
        case 'd':
        case 'D':
            y-=currentSpeed;
            distance += currentSpeed;
            break;
        case 'r':
        case 'R':
            x+=currentSpeed;
            distance += currentSpeed;
            break;
        case 'l':
        case 'L':
            x-=currentSpeed;
            distance += currentSpeed;
            break;
        default:
            cout << "Invalid direction." << endl;
    }
    cout << name << "'s position is now " << x << ", " << y << endl;
    lastCommand = d;
    return;
}
