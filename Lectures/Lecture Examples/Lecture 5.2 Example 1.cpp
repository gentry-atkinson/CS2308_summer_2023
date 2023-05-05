#include<iostream>

using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int v){val = v;next = NULL;}
};

void printList(Node* h){
    while(h != NULL){
        cout << h->val << ' ';
        h = h->next;
    }
    cout << endl;
}

void selectionSort(Node* head)
{
    //from: https://www.geeksforgeeks.org/iterative-selection-sort-for-linked-list/
    Node* temp = head;
    while (temp != NULL) {
        Node* min = temp;
        Node* r = temp->next;
        while (r) {
            if (min->val > r->val)
                min = r;
 
            r = r->next;
        }
        int x = temp->val;
        temp->val = min->val;
        min->val = x;
        temp = temp->next;
    }
}


int main(int argc, char** argv){
    Node* head = new Node(4);
    Node* maker = head;
    maker->next = new Node(2);
    maker = maker->next;
    maker->next = new Node(7);
    maker = maker->next;
    maker->next = new Node(3);
    maker = maker->next;
    maker->next = new Node(6);
    maker = NULL;
    printList(head);
    selectionSort(head);
    printList(head);
} //try to guess the output
