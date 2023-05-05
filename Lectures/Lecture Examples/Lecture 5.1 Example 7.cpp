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

void deleteNode(int target, Node* next){
    Node* prev = NULL;
    while(next!=NULL){
        if(next->value == target)
            break;
        prev = next;
        next = next->next;
    }
    prev->next = next->next;
    delete next;
}

void insetBetween(int newVal, Node* p, Node* n){
    p->next = new Node(newVal);
    p->next->next = n;
}

int main(int argc, char** argv){
    Node* head = new Node(3);
    head->next = new Node(6);
    head->next->next = new Node(4);
    insetBetween(1, head->next, head->next->next);
    printList(head);
    return 0;
} //try to guess the output