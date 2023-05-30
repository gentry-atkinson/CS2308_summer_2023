#include "RoboList.h"

using namespace std;

RoboList::~RoboList()
{
    Node* t = head;
    //cout << "Deleting robot list" << endl;
    while(head != NULL){
        t = head;
        head = head->next;
        delete t;
    }
}

Robot* RoboList::findRobot(string target){
    Node* t = head;
    while(t != NULL){
        if(t->val->getName() == target){
            return t->val;
        }
        t = t->next;
    }
    return NULL;
}

void swap(string s[], int i[], int a, int b){
    string temp_s = s[a];
    int temp_i = i[a];
    s[a] = s[b];
    i[a] = i[b];
    s[b] = temp_s;
    i[b] = temp_i;
}

void RoboList::printDistances(){
    if (SIZE == 0) return;
    string names[SIZE];
    int distances[SIZE];
    Node* t = head;
    int i = 0;
    while (t != NULL){
        names[i] = t->val->getName();
        distances[i] = t->val->getDistance();
        t = t->next;
        i++;
    }

    bool sorted;
    for(int i = SIZE-1; i > 0; i--){
        sorted = true;
        for (int j = 0; j<i; j++){
            if(distances[j]<distances[j+1]){
                swap(names, distances, j, j+1);
                sorted = false;
            }
        }
        if(sorted) break;
    }
    cout << "Name\t\tDistance" << endl;
    cout << "----------------------" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << names[i] << '\t' << distances[i] << endl;
    }
}

void RoboList::printList(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val->getName() << "\t" << temp->val->getDistance()
            << endl;
        temp = temp->next;
    }
}

void RoboList::ins(string n){
    Node* t = new Node;
    t->val = new Robot(n);
    t->next = head;
    head = t;
    SIZE++;
    cout << n << " is now in the list." << endl;
}
void RoboList::del(string n){
    Node* temp = head;
    if(head->val->getName() == n){
        head = head->next;
        delete temp;
        SIZE--;
        cout << n << " removed from the list." << endl;
        return;
    }
    while(temp != NULL){
        if (temp->next->val->getName()==n){
            Node* delThis = temp->next;
            temp->next = temp->next->next;
            delete delThis;
            SIZE--;
            cout << n << " removed from the list." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "No matching name found to delete." << endl;
    return;
}
