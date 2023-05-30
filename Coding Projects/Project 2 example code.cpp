/*********************************************
*Author: Gentry Atkinson                     *
*Date: 16 February, 2011                     *
*Collaborators: none                         *
*Description: track multiple robots          *
*********************************************/

#include<iostream>
#include <ctype.h>

using namespace std;

struct Robot{
    int x=0;
    int y=0;
    char lastCommand = 'z';
    int currentSpeed = 1;
    int distance = 0;
    string name;
};

int findRobot(Robot* allRobots[], int SIZE, string identifier){
    for(int i = 0; i < SIZE; i++){
        if(allRobots[i]->name == identifier) return i;
    }
    return -1;
}

void moveRobot(Robot* r, char d){
    if(toupper(r->lastCommand) == toupper(d)){
        if(r->currentSpeed < 4) r->currentSpeed += 1;
    }
    else{
        r->currentSpeed = 1;
    }
    switch(d){
        case 'u':
        case 'U':
            r->y+=r->currentSpeed;
            r->distance += r->currentSpeed;
            break;
        case 'd':
        case 'D':
            r->y-=r->currentSpeed;
            r->distance += r->currentSpeed;
            break;
        case 'r':
        case 'R':
            r->x+=r->currentSpeed;
            r->distance += r->currentSpeed;
            break;
        case 'l':
        case 'L':
            r->x-=r->currentSpeed;
            r->distance += r->currentSpeed;
            break;
        default:
            cout << "Invalid direction." << endl;
    }
    cout << r->name << "'s position is now " << r->x << ", " << r->y << endl;
    r->lastCommand = d;
    return;
}

void printDistances(Robot** roboList, int SIZE){
    for(int i = 0; i < SIZE; i++){
        for(int j = SIZE-1; j > i; j--){
            if(roboList[j]->distance > roboList[j-1]->distance){
                Robot* temp = roboList[i];
                roboList[i] = roboList[j];
                roboList[j] = temp;
            }
        }
    }
    for(int i = 0; i < SIZE; i++){
            cout << roboList[i]->name << '\t'
                << roboList[i]->distance << endl;
        }
}

Robot** makeBotList(int SIZE){
    Robot** botList = new Robot*[SIZE];
    for(int i = 0; i < SIZE; i++){
        botList[i] = new Robot;
    }
    return botList;
}

int main(int argc, char** argv){
    cout << "Welcome to MultiRobo Guider!" << endl;
    cout << "How many robots are you tracking: ";
    int numBots;
    cin >> numBots;
    Robot** botList = makeBotList(numBots);

    cout << "Please enter names for the " << numBots << " robots." << endl;
    for(int i = 0; i < numBots; i++){
        cin >> botList[i]->name;
    }

    bool programRunning = true;

    while(programRunning){
        char menuChoice, directionChoice;
        string roboName;
        int roboIndex;

        cout << "Please select: " << endl;
        cout << "  M- move" << endl;
        cout << "  D- distance" << endl;
        cout << "  Q- quit" << endl;
        cin >> menuChoice;

        switch(menuChoice){
            case 'm':
            case 'M':
                cin >> roboName;
                roboIndex = findRobot(botList, numBots, roboName);
                if(roboIndex == -1)
                    cout << "That robot does not exist." << endl;
                else{
                    cin >> directionChoice;
                    moveRobot(botList[roboIndex], directionChoice);
                }
                break;
            case 'd':
            case 'D':
                // for (int i = 0; i < numBots; i++){
                //     cout << botList[i].name << '\t' << botList[i].distance
                //         << endl;
                // }
                printDistances(botList, numBots);
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
    for(int i = 0; i < numBots; i++){
        delete botList[i];
    }
    delete [] botList;
    return 0;
}

