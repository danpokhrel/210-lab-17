// COMSC-210 | Lab 17 | Dan Pokhrel
// IDE used: Visual Studio Code
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// Prototypes
void pushFront(Node *head, Node *node); // Adds node to front of list
void insertNode(Node *head, int i, Node *node); // Adds node after i-th node
void deleteNode(Node *head, int i); // Deletes i-th node
void deleteList(Node *head); // Deletes entire list
void output(Node *head); // Prints data in list

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        pushFront(head, newVal);
    }
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry-1);
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    insertNode(head, entry-1, newnode);
    output(head);

    // deleting the linked list
    deleteList(head);
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}