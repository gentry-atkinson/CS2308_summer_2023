#define NULL nullptr

#include<fstream>
#include<iostream>

class IntStack{
    private:
        class Node{
            int val;
            Node* next;
            Node(int i){val = i;}
        };
        Node * head = NULL;
    public:
        IntStack();
        void push(int i);
        int pop();
};

class IntQueue{
    private:
        class Node{
            int val;
            Node* next;
            Node(int i){val = i;}
        };
        Node * front = NULL;
        Node * rear = NULL;
    public:
        IntQueue();
        void enqueue(int i);
        int dequeue();
};

class Character{
    private:
        int health;
        std::string name;
        int locationX;
        int locationY;

    public:
        Character(){
            std::ifstream charFile("char_config.txt");
            charFile >> health;
            charFile >> name;
            locationX = locationY = 0;
        }
        void updateLocation(int x, int y){
            locationX = x;
            locationY = y;
        }
        void takeDamage(int d){
            health -= d;
            if (health == 0){
                std::cout << name << " has died." << std::endl;
            }
        }
        std::string getName(){
            return name;
        }
};

class Dungeon{
    private:
        int level;
        std::string description;
        std::string boss;
    public:
        int getLevel() {return level;}
        std::string getDesc(){return description;}
        std::string getBoss(){return boss;}
};