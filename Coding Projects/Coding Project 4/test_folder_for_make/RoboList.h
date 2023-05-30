#ifndef ROBOLIST_H
#define ROBOLIST_H

#include "Robot.h"

class RoboList
{
    private:
        class Node{
            public:
                Robot* val;
                Node* next;
        };
        Node* head = NULL;
        int SIZE = 0;

    public:
        Robot* findRobot(std::string target);
        void printDistances();
        void printList();
        void ins(std::string);
        void del(std::string);
        ~RoboList();
};

#endif // ROBOLIST_H
