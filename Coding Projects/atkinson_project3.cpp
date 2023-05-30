/*********************************************
*Author: Gentry Atkinson                     *
*Date: 16 February, 2011                     *
*Collaborators: none                         *
*Description: track multiple robots          *
*********************************************/

#include<iostream>
#include <ctype.h>

using namespace std;

class Robot{
    private: 
        int x=0;
        int y=0;
        char lastCommand = 'z';
        int currentSpeed = 1;
        int distance = 0;
        string name;
    public:
        Robot(){
            ;
        }
        string getName(){return name;}
        int getDistance(){return distance;}

        void setName(string name){this->name = name;}
        void moveRobot(char d);
};

int findRobot(Robot* allRobots[], int SIZE, string identifier){
    for(int i = 0; i < SIZE; i++){
        if(allRobots[i]->getName() == identifier) return i;
    }
    return -1;
}

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

void printDistances(Robot** roboList, int SIZE){
    for(int i = 0; i < SIZE; i++){
        for(int j = SIZE-1; j > i; j--){
            if(roboList[j]->getDistance() > roboList[j-1]->getDistance()){
                Robot* temp = roboList[i];
                roboList[i] = roboList[j];
                roboList[j] = temp;
            }
        }
    }
    for(int i = 0; i < SIZE; i++){
            cout << roboList[i]->getName() << '\t'
                << roboList[i]->getDistance() << endl;
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
        string name;
        cin >> name;
        botList[i]->setName(name);
    }

    bool programRunning = true;

    while(programRunning){
        char menuChoice, directionChoice;
        string roboName, newName;
        int roboIndex;

        cout << "Please select: " << endl;
        cout << "  M- move" << endl;
        cout << "  D- distance" << endl;
        cout << "  R- rename" << endl;
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
                    botList[roboIndex]->moveRobot(directionChoice);
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
            case 'r':
            case 'R':
                cin >> roboName >> newName;
                roboIndex = findRobot(botList, numBots, roboName);
                botList[roboIndex]->setName(newName);
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

