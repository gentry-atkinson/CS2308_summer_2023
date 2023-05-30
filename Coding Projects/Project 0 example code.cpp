/*********************************************
*Author: Gentry Atkinson                     *
*Date: 6 February, 2023                     *
*Collaborators: none                         *
*Description: track one robot                *
*********************************************/

#include<iostream>

using namespace std;

struct Robot{
    int x=0;
    int y=0;
    char lastCommand = 'z';
};

//Move Robot
//Parameters:
//  r, a Robot to move
//  d, the direction to move r
//Returns: nothing
//Side Effects: the x, y, and lastCommand members of r are altered
void moveRobot(Robot &r, char d){
    switch(d){
        case 'u':
        case 'U':
            r.y+=1;
            break;
        case 'd':
        case 'D':
            r.y-=1;
            break;
        case 'r':
        case 'R':
            r.x+=1;
            break;
        case 'l':
        case 'L':
            r.x-=1;
            break;
        default:
            cout << "Invalid direction." << endl;
    }
    cout << "Robot's position is now " << r.x << ", " << r.y << endl;
    r.lastCommand = d;
    return;
}

int main(int argc, char** argv){
    cout << "Welcome to MultiRobo Guider!" << endl;

    bool programRunning = true;
    Robot r;

    cout << "Robot's position is " << r.x << ' ' << r.y << endl;

    while(programRunning){
        char menuChoice, directionChoice;

        cout << "Please select: " << endl;
        cout << "  U - move 1 space in the Y direction" << endl
            << "  D- move -1 space in the Y direction" << endl
            << "  R- move 1 space in the X direction" << endl
            << "  L- move -1 space in the X direction" << endl
            << "  Q- quit the program" << endl;
        cin >> menuChoice;

        switch(menuChoice){
            case 'u':
            case 'U':
                moveRobot(r, 'u');
                break;
            case 'd':
            case 'D':
                moveRobot(r, 'd');
                break;
            case 'r':
            case 'R':
                moveRobot(r, 'r');
                break;
            case 'l':
            case 'L':
                moveRobot(r, 'l');
                break;
            case 'q':
            case 'Q':
                cout << "Goodbye." << endl;
                programRunning = false;
                break;
            default:
                cout << "Command not recognized." << endl;
        }
    }

    return 0;
}

