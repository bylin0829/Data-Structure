#include <iostream>

using namespace std;

/*
    Declare class
*/
class LinkedList;

class Node{
    private:
        int data;
        Node *next;
    
    public:
        Node():data(0),next(nullptr){}; //Nothing to do
        Node(int value):data(value),next(nullptr){};
    
    friend class LinkedList;
};

class LinkedList{
    private:
        Node *header;    //The header node in list
    public:
        LinkedList():header(){};    //Declare header node
        void PrintList();           //Print all of data from list
        void PushFront(int x);      //Add a node before the header node
        void PushBack(int x);       //Add a node after the last node
        void Delete(int x);         //Delete element
        void Clear();               //Delete all of data from list
        void Reverse();             //Reverse List
};


/*
    Implementation
*/
void LinkedList::PrintList(){
    if(header == nullptr){
        cout << "List is empty" << endl;
        return;
    }

    Node *current = header;
    for(int i =0; current != nullptr;i++){
        cout << "Node[" << i << "]:" << current->data << endl;
        current = current->next; // Move pointer to next node
    }
    cout << "PrintList Done." << endl;
}

void LinkedList::PushBack(int x){
    Node *newnode = new Node(x); // Decalre new node

    if(header == nullptr){
        header = newnode;
        return;
    }

    // Check from the header node.  If the next address is nullptr, push the new node from back.
    Node *current = header;
    while(current->next != nullptr){
        current = current->next;
    }
    
    current->next = newnode; //Move pointer to new node
}

void LinkedList::PushFront(int x){
    Node *newnode = new Node(x); // Decalre new node

    if(header == nullptr){
        header = newnode;
        return;
    }

    newnode->next = header;
    header = newnode; // Update header header
}

void LinkedList::Clear(){
    // Set the next pointer to nullptr in header.
    header = nullptr;
}

void LinkedList::Delete(int x){
    //Delete specific element from the list.

    //Special case
    if(header == nullptr){
        return;
    }

    if(header->data==x){
        if(header->next == nullptr){
            //only one node
            header = nullptr;
        }
        else{
            //not only one node
            header = header->next;
        }
        return;
    }

    //Start from second node
    Node *node_previous = header;
    Node *node_current = node_previous->next;
    Node *node_next = node_current->next;
    while(node_current != nullptr){
        if(node_current->data == x){
            node_previous->next = node_next;
            return;
        }

        //Change to next node
        node_previous = node_current;
        node_current = node_current->next;
        node_next = node_current->next;
    }
}

void LinkedList::Reverse(){
    //Special case
    if(header == nullptr || header->next == nullptr){
        return;
    }

    Node *current = header;
    LinkedList temp;

    while(current != nullptr){
        temp.PushFront(current->data);
        current = current->next;
    }
    header = temp.header;
}

/*
    Main
*/

int main(int argc, char* argv[]){
    cout << "This is linkedlist practice." << endl;

    LinkedList a;
    
    a.PrintList();
    a.PushFront(23);
    a.PushBack(50);
    a.PrintList();
    a.PushFront(9);
    a.PrintList();
    a.Clear();
    a.PrintList();
    a.PushBack(666);
    a.PushFront(19);
    a.PushBack(-5);
    a.PrintList();
    a.Delete(19);
    a.Delete(-5);
    a.PrintList();
    a.PushFront(1317);
    a.PushFront(120);
    a.PushBack(97143);
    a.PrintList();
    a.Reverse();
    a.PrintList();
    return 0;
}