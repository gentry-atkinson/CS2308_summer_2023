#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>

class Robot{
    private:
        int x=0;
        int y=0;
        char lastCommand = 'z';
        int currentSpeed = 1;
        int distance = 0;
        std::string name;
    public:
        Robot(std::string);

        std::string getName();
        int getDistance();

        void setName(std::string name);
        void moveRobot(char d);
};

#endif // ROBOT_H
