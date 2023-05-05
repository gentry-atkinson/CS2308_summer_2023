#include<iostream>

using namespace std;

class LinkedList{
    private:
        class Node{
            public:
                int val;
                Node* next;
                Node(int v){val = v;next = NULL;}
        };
        Node* head;
        Node* tail;
    public:
        void insert(int v);
        void del(int v);
        bool isEmpty();
        void printList();
        bool searchList(int v);
        void delList();
        LinkedList(){head=NULL;tail=NULL;}
        ~LinkedList(){delList();}
};

void LinkedList::insert(int v){
    if(head==NULL){
        head = new Node(v);
        tail = head;
    }
    else{
        tail->next = new Node(v);
        tail = tail->next;
    }
}

void LinkedList::del(int v){
    Node* leading = head;
    Node* following = NULL;
    while(leading->val != v){
        following = leading;
        leading = leading->next;
        if(leading == NULL) return;
    }
    if(leading == head)
        head = head->next;
    else if(leading == tail){
        tail = following;
        tail->next = NULL;
    }
    else
        following->next = leading->next;
    delete leading;
}

bool LinkedList::isEmpty(){
    return head==NULL;
}

void LinkedList::printList(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val << ' ';
        temp = temp->next;
    }
    cout << endl;
}

bool LinkedList::searchList(int v){
    Node* temp = head;
    while(temp != NULL){
        if(temp->val == v) return true;
        temp = temp->next;
    }
    return false;
}

void LinkedList::delList(){
    Node* following = head;
    while(head != NULL){
        head = head->next;
        delete following;
        following = head;
    }
    tail = NULL;
}


int main(int argc, char** argv){
    LinkedList myList;
    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.printList();
    if (myList.searchList(5))
        cout << "found it" << endl;
    else
        cout << "not here" << endl;
} //try to guess the output
