//Author: Gentry
//Date: Feb 22, 2023
//Collabs: none

#include<iostream>
#include<iomanip>
#include<ctype.h>

using namespace std;

//5.1 Robot struct
//The program should store the robot’s name, speed, and positional data
//in a struct with the following members:
//•X- the current X value of the robot’s position
//•Y- the current Y value of the robot’s position
//•lastCommand- the last direction that the robot moved
//•currentSpeed- the speed that the robot is traveling
//•distance- the total distance that the robot has traveled
//•name- the name of the robot

struct Robot{
    int X = 0;
    int Y = 0;
    char lastCommand = 'z';
    int currentSpeed = 1;
    int distance = 0;
    string name;
};

//5.2 findRobot function
//This function should find the index of one Robot in the array of
//Robots using its unique identifier.
//The parameters of this function are:
//•Robot[] roboList: a list of robots
//•string identifier: the target unique identifier
//•SIZE: the number of robots in roboList
//Return the index of the robot with a matching identifier as an int,
//or -1 if the identifier is not in the list.
//Side effects: none
int findRobot(const Robot roboList[], string identifier, int SIZE){
    //Apply sequential search to roboList looking for identifier

    //Iterate over every robot in the list
    for(int i = 0; i < SIZE; i++){
        //If this robot's name is identifier, return this index
        if(roboList[i].name == identifier){
            return i;
        }
    }
    //Return -1
    return -1;
}

//5.3 moveRobot function
//The position of the robot struct should be updated using a void
//function called moveRobot.
//The parameters of this function are:
//•Robot r: a Robot passed by reference
//•char d: a character value representing one direction
//The robot’s position should be updated as described in Section 4.3
//(so if d == ‘U’, then increase r.y by r.currentSpeed, etc.)
//This function also needs to update the current speed and the distance
//traveled for the robot. The robot’s speed increases by one unit every
//time it moves in the same direction up to a maximum speed of four.
//See Section 5.1 for more information about speed and distance.
//Only this function should be used to change the robot’s position
//after the initial position has been set.
//Side effects: r's currentSpeed, X, Y, lastCommand are all updated
void moveRobot(Robot& r, char direction){
    //If d is equal to last command, speed up to a maximum of 4
    if(toupper(direction) == toupper(r.lastCommand)){
        if(r.currentSpeed < 4) r.currentSpeed += 1;
    }
    //Else currentSpeed = 1;
    else{
        r.currentSpeed = 1;
    }

    switch(direction){
    //if dir is u, move up
    case 'u':
    case 'U':
        r.Y += r.currentSpeed;
        break;
    //if dir is d, move down
    case 'd':
    case 'D':
        r.Y -= r.currentSpeed;
        break;
        break;
    //if dir is r, move right
    case 'r':
    case 'R':
        r.X += r.currentSpeed;
        break;
    //if dir is l, move left
    case 'l':
    case 'L':
        r.X -= r.currentSpeed;
        break;
    //if anything else print an error
    default:
        cout << "Unrecognized direction" << endl;
        return;
    }
    r.distance += r.currentSpeed;
    cout << r.name << "'s position is now (" << r.X << " ," << r.Y << ")"
        << endl;
    //set r.lastCommand to dir
    r.lastCommand = direction;
}

int main(){
    cout << "How many robots: ";
    int numRobots;
    cin >> numRobots;
    Robot roboList[numRobots];

    for(int i = 0; i < numRobots; i++){
        cout << "Name this robot: ";
        cin >> roboList[i].name;
    }
    char input, dir;
    string roboName;
    int roboIndex;
    do{
        cout << "M- move" << endl
            << "D- distance" << endl
            << "Q- quit" << endl;
        cin >> input;

        switch(input){
        //if move
        case 'm':
        case 'M':
            //find the correct robot in the array
            cout << "What robot: ";
            cin >> roboName;
            roboIndex = findRobot(roboList, roboName, numRobots);
            //if not there, print error
            if(roboIndex == -1){
                cout << "Robot not found" << endl;
            }
            //otherwise move the correct robot
            else{
                cout << "U, D, L, R: ";
                cin >> dir;
                moveRobot(roboList[roboIndex], dir);
            }
            break;

        //if distance
        case 'd':
        case 'D':
            //iterate over array of robots
            for(int i = 0; i < numRobots; i++){
                //print name and distance
                cout << setw(15) << left <<roboList[i].name
                    << roboList[i].distance << endl;
            }
            break;
        //if quit
        case 'q':
        case 'Q':
            //print goodbye
            cout << "Goodbye" << endl;
            break;
        //if anything else, print error
        default:
            cout << "Invalid input." << endl;
        }

    }while(input != 'q'  && input != 'Q');
}
