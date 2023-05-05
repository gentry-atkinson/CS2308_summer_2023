#include<iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int v){
            value = v;
            next = NULL;
        }

};

void printList(Node* h){
    while(h!=NULL){
        cout << h->value << ' ';
        h = h->next;
    }
    cout << endl;
}

int main(int argc, char** argv){
    Node* head = new Node(6);
    Node* newNode = new Node(3);
    newNode->next = head;
    head = newNode;
    cout << head << endl;
    printList(head);
    cout << head << endl;
    return 0;
} //try to guess the output