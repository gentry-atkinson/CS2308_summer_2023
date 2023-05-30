/*********************************************
*Author: Gentry Atkinson                     *
*Date: 16 February, 2011                     *
*Collaborators: none                         *
*Description: track multiple robots          *
*********************************************/

#include<iostream>

#include "include/Robot.h"
#include "include/RoboList.h"

using namespace std;



//int findRobot(Robot* allRobots[], int SIZE, string identifier){
//    for(int i = 0; i < SIZE; i++){
//        if(allRobots[i]->getName() == identifier) return i;
//    }
//    return -1;
//}
//
//void printDistances(Robot** roboList, int SIZE){
//    for(int i = 0; i < SIZE; i++){
//        for(int j = SIZE-1; j > i; j--){
//            if(roboList[j]->getDistance() > roboList[j-1]->getDistance()){
//                Robot* temp = roboList[i];
//                roboList[i] = roboList[j];
//                roboList[j] = temp;
//            }
//        }
//    }
//    for(int i = 0; i < SIZE; i++){
//            cout << roboList[i]->getName() << '\t'
//                << roboList[i]->getDistance() << endl;
//        }
//}
//
//Robot** makeBotList(int SIZE){
//    Robot** botList = new Robot*[SIZE];
//    for(int i = 0; i < SIZE; i++){
//        botList[i] = new Robot;
//    }
//    return botList;
//}

int main(int argc, char** argv){
    cout << "Welcome to MultiRobo Guider!" << endl;
    cout << "How many robots are you tracking: ";
    int numBots;
    cin >> numBots;
    //Robot** botList = makeBotList(numBots);
    RoboList botList;

    cout << "Please enter names for the " << numBots << " robots." << endl;
    for(int i = 0; i < numBots; i++){
        string name;
        cin >> name;
        //botList[i]->setName(name);
        botList.ins(name);
    }

    bool programRunning = true;

    while(programRunning){
        char menuChoice, directionChoice;
        string roboName, newName;
        //int roboIndex;
        Robot* roboPtr;

        cout << "Please select: " << endl;
        cout << "  M- move" << endl;
        cout << "  D- distance" << endl;
        cout << "  U- update list" << endl;
        cout << "  R- rename" << endl;
        cout << "  Q- quit" << endl;
        cin >> menuChoice;

        switch(menuChoice){
            case 'm':
            case 'M':
                cin >> roboName;
                //roboIndex = findRobot(botList, numBots, roboName);
                roboPtr = botList.findRobot(roboName);
                //if(roboIndex == -1)
                if(roboPtr == NULL)
                    cout << "That robot does not exist." << endl;
                else{
                    cin >> directionChoice;
                    //botList[roboIndex]->moveRobot(directionChoice);
                    roboPtr->moveRobot(directionChoice);
                }
                break;
            case 'd':
            case 'D':
                // for (int i = 0; i < numBots; i++){
                //     cout << botList[i].name << '\t' << botList[i].distance
                //         << endl;
                // }
                //printDistances(botList, numBots);
                botList.printDistances();
                break;
            case 'r':
            case 'R':
                cin >> roboName >> newName;
                //roboIndex = findRobot(botList, numBots, roboName);
                roboPtr = botList.findRobot(roboName);
                //botList[roboIndex]->setName(newName);
                roboPtr->setName(newName);
                break;
            case 'u':
            case 'U':
                cin >> directionChoice;
                switch(directionChoice){
                    case 'a':
                    case 'A':
                        cin >> roboName;
                        botList.ins(roboName);
                        break;
                    case 'd':
                    case 'D':
                        cin >> roboName;
                        botList.del(roboName);
                        break;
                    default:
                        cout << "Invalid choice to update." << endl;
                }
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
//    for(int i = 0; i < numBots; i++){
//        delete botList[i];
//    }
//    delete [] botList;
    return 0;
}

