// COMSC-210 | Lab 17 | Dan Pokhrel
// IDE used: Visual Studio Code
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node { // linked list node
    float value;
    Node *next = nullptr;
};

// Prototypes
void pushFront(Node **head, Node *node); // Adds node to front of list
void pushBack(Node **head, Node *node); // Adds node to back of list
void insertNode(Node *head, int i, Node *node); // Adds node after i-th node
void deleteNode(Node **head, int i); // Deletes i-th node
void deleteList(Node **head); // Deletes entire list
void output(Node *head); // Prints data in list

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        Node *newVal = new Node;
        newVal->value = rand() % 100;
        pushFront(&head, newVal);
    }
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(&head, entry-1);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    Node * newnode = new Node;
    newnode->value = 10000;
    insertNode(head, entry-1, newnode);
    output(head);

    // deleting the linked list
    deleteList(&head);
    output(head);

    return 0;
}

void pushFront(Node **head, Node *node){
    if (!head) // First node
        *head = node;
    else{ // Add node before head
        node->next = *head;
        *head = node;
    }
}

void pushBack(Node **head, Node *node){
    if (!(*head)){ // First node
        *head = node;
        return;
    }
    Node *current = *head;
    while (current->next) // iterate through list
        current = current->next;

    current->next = node;
}

void insertNode(Node *head, int i, Node *node){
    if (i < 0){
        cout << "\nInvalid input\n";
        return;
    }
    Node *current = head;
    Node *previous = head;
    // Traverse to desired node
    for (int j = 0; j <= i; j++){
        if (!current || !previous) { // Out of bounds
            cout << "\nInvalid input\n";
            return;
        }

        else if (j == 0)
            current = current->next;
        else {
            current = current->next;
            previous = previous->next;
        }
    }
    // Insert Node
    node->next = current;
    previous->next = node;
}

void deleteNode(Node **head, int i){
    if (i < 0){
        cout << "\nInvalid input\n";
        return;
    }
    Node *current = *head;
    Node *previous = *head;
    // Traverse to desired node
    for (int j = 0; j < i; j++){
        if (!current->next){ // Out of bounds
            cout << "\nInvalid input\n";
            return;
        }

        else if (j == 0)
            current = current->next;
        else {
            current = current->next;
            previous = previous->next;
        }
    }
    // Delete node
    if (current){
        if (current == previous) // first node
            *head = current->next;
        else if (current->next) // isn't last node
            previous->next = current->next;
        else // last node
            previous->next = nullptr;
        delete current;
    }
}

void deleteList(Node **head){
    Node *current = *head;
    while (current){ // iterate through list
        *head = current->next;
        delete current;
        current = *head;
    }
    *head = nullptr;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) { // iterate through list
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}