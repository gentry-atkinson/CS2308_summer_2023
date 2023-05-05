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
    Node* head = new Node(3);
    head->next = new Node(6);
    head->next->next = new Node(4);
    Node* oldHead = head;
    head = head->next;
    delete oldHead;
    printList(head);
    return 0;
} //try to guess the output